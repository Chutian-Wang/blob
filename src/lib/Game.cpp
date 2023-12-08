#include "Game.h"

#include <GL/glut.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>

#include <cmath>
#include <vector>
#include <iostream>

#include "Basics.h"
#include "Controls.h"
#include "NPC.h"
#include "Player.h"


Game::Game() {
  this->score = 0;
  this->running = false;

  srand(time(NULL));

  // initialize blobs with random pos
  this->player = std::make_unique<Player>(15, Vec2(0, 0), Vec2(0, 0), RED);

  for (int i = 0; i < NPC_AMOUNT; i++) {
    auto npc = std::make_unique<NPC>(
        15,
        Vec2(WIN_WIDTH * 2 * ((float)rand() / (float)(RAND_MAX / 1) - 0.5),
             WIN_HEIGHT * 2 * ((float)rand() / (float)(RAND_MAX / 1) - 0.5)),
        Vec2(WIN_WIDTH * 2 * ((float)rand() / (float)(RAND_MAX / 1) - 0.5),
             WIN_HEIGHT * 2 * ((float)rand() / (float)(RAND_MAX / 1) - 0.5))
            .normalize(),
        BLUE);
    blobs.push_back(std::move(npc));
  }
  for (int i = 0; i < FOOD_AMOUNT; i++) {
    auto food = std::make_unique<Food>(
        10,
        Vec2(WIN_WIDTH * 2 * ((float)rand() / (float)(RAND_MAX / 1) - 0.5),
             WIN_HEIGHT * 2 * ((float)rand() / (float)(RAND_MAX / 1) - 0.5)),
        GREEN);
    blobs.push_back(std::move(food));
  }
}

void Game::update() {
    // updates
    if (!end) {
    player->update(*this);
    for (auto& blob : blobs) {
        if (blob) blob->update(*this);
    }
    // collision detection between player and blobs
    for (auto& blob : blobs) {
        if (!blob) continue;
        if ((player->pos - blob->pos).norm() < player->radius + blob->radius) {
        // collision!
        if (player->radius > blob->radius) {
            // player eats blob
            player->radius = sqrt((player->radius * player->radius) +
                                (blob->radius * blob->radius));
            this->score += blob->radius;
            blob.reset();
        } else {
            // player dies
            // blob->radius = sqrt((player->radius * player->radius) +
            //                     (blob->radius * blob->radius));
            player->alive = false;
            player->score = 0;
            end_game();
        }
        }
    }

    // collision detection between blobs;
    for (size_t i = 0; i < blobs.size(); ++i) {
        for (size_t j = 0; j < blobs.size(); ++j) {
        // check if nullptr
        if (i == j) continue;
        if (blobs[i] && blobs[j]) {
            if ((blobs[i]->pos - blobs[j]->pos).norm() <
                blobs[i]->radius + blobs[j]->radius) {
            if (blobs[i]->radius < blobs[j]->radius) {
                // update survivor size
                blobs[j]->radius = sqrt((blobs[i]->radius * blobs[i]->radius) +
                                        (blobs[j]->radius * blobs[j]->radius));
                blobs[i].reset();
            } else {
                // update survivor size
                blobs[i]->radius = sqrt((blobs[i]->radius * blobs[i]->radius) +
                                        (blobs[j]->radius * blobs[j]->radius));
                blobs[j].reset();
            }
            }
        }
        }
    }
    }
}

void Game::start_game() {
  running = true;
  update();
}

void Game::end_game() {
  end = true;
}

void Game::render() {
  
  Color textColor = Color(0.0, 0.0, 0.0);
  Basics::DrawStartText(0.5, 0.5, textColor);

  if (!running) {
    if (Controls::get_key_state('t')) {
        running = true;
    }
    Basics::DrawStartText(0, 0, textColor);
  } else {
      if (player) player->render();
        for (size_t i = 0; i < blobs.size(); i++) {
            if (blobs[i]) blobs[i]->render();
    }
  }

  if (end) {
    //   std::cout << player->pos.x << player->pos.y << std::endl;
    //   float fx = (float)player->pos.x/WIN_WIDTH*2-1;
    //   float fy = (float)player->pos.y/WIN_HEIGHT*2-1;
      Basics::DrawEndText(player->pos.x, player->pos.y, textColor);
  }
}
