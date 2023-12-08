#include "Game.h"

#include <GL/glut.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>

#include <cmath>
#include <vector>

#include "Controls.h"
#include "npc.h"
#include "player.h"

Game::Game() {
  srand(time(NULL));
  // key update related
  for (int i = 0; i < 256; i++) {
    Controls::key_states[i] = 0;
  }
  // bind callbacks
  glutKeyboardFunc(Controls::keypress_cb);
  glutKeyboardUpFunc(Controls::keyup_cb);

  // initialize blobs with random pos
  auto player = std::make_unique<Player>(
      3,
      Vec2(rand() % (int)(WIN_WIDTH / 2.0f) + WIN_WIDTH / 2.0f,
           rand() % (int)(WIN_HEIGHT / 2.0f) + WIN_HEIGHT / 2.0f),
      Vec2(0, 0), RED);
  blobs.push_back(std::move(player));

  for (int i = 0; i < NPC_AMOUNT; i++) {
    auto npc = std::make_unique<NPC>(
        3,
        Vec2(rand() % (int)(WIN_WIDTH / 2.0f) + WIN_WIDTH / 2.0f,
             rand() % (int)(WIN_HEIGHT / 2.0f) + WIN_HEIGHT / 2.0f),
        Vec2(0, 0), BLUE);
    blobs.push_back(std::move(npc));
  }
  for (int i = 0; i < FOOD_AMOUNT; i++) {
    auto food = std::make_unique<Food>(
        1,
        Vec2(rand() % (int)(WIN_WIDTH / 2.0f) + WIN_WIDTH / 2.0f,
             rand() % (int)(WIN_HEIGHT / 2.0f) + WIN_HEIGHT / 2.0f),
        GREEN);
    blobs.push_back(std::move(food));
  }
}

void Game::update() {
  // updates
  player->update(*this);
  for (auto& blob : blobs) {
    blob->update(*this);
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
  player->render();
  for (size_t i = 0; i < blobs.size(); i++) {
    blobs[i]->render();
  }
}