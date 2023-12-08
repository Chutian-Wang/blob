#include "Game.h"

#include <GL/glut.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>

#include <cmath>
#include <vector>

#include "Controls.h"
#include "NPC.h"
#include "Player.h"
#include "Basics.h"

Game::Game() {
  this->score = 0;
  this->start = false;

  srand(time(NULL));

  // initialize blobs with random pos
  this->player = std::make_unique<Player>(20, Vec2(0, 0), Vec2(0, 0), RED);

  for (int i = 0; i < NPC_AMOUNT; i++) {
    auto npc = std::make_unique<NPC>(
        20,
        Vec2(rand() % WIN_WIDTH, rand() % WIN_HEIGHT),
        Vec2(0, 0), BLUE);
    blobs.push_back(std::move(npc));
  }
  for (int i = 0; i < FOOD_AMOUNT; i++) {
    auto food = std::make_unique<Food>(
        5,
        Vec2(rand() % WIN_WIDTH, rand() % WIN_HEIGHT),
        GREEN);
    blobs.push_back(std::move(food));
  }
}

void Game::update() {
  // updates
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
        blob->radius = sqrt((player->radius * player->radius) +
                            (blob->radius * blob->radius));
        player->alive = false;
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

void Game::start_game() {
  start = true;
  update();
}

void Game::render() {
  if (!start) {
    Basics::DrawText(WIN_WIDTH / 2 - 50, WIN_HEIGHT / 2, RED);
  }
  else {
    if (player) player->render();
    for (size_t i = 0; i < blobs.size(); i++) {
      if (blobs[i]) blobs[i]->render();
    }
  }
}