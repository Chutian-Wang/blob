#include "Game.h"

#include <GL/glut.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>

#include <cmath>
#include <iostream>
#include <vector>

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
        Vec2(WIN_WIDTH * WORLD_SIZE * 2 *
                 ((float)rand() / (float)(RAND_MAX / 1) - 0.5),
             WIN_HEIGHT * WORLD_SIZE * 2 *
                 ((float)rand() / (float)(RAND_MAX / 1) - 0.5)),
        Vec2(((float)rand() / (float)(RAND_MAX / 1) - 0.5),
             ((float)rand() / (float)(RAND_MAX / 1) - 0.5))
            .normalize(),
        BLUE);
    blobs.push_back(std::move(npc));
  }
  for (int i = 0; i < FOOD_AMOUNT; i++) {
    auto food = std::make_unique<Food>(
        10,
        Vec2(WIN_WIDTH * WORLD_SIZE * 2 *
                 ((float)rand() / (float)(RAND_MAX / 1) - 0.5),
             WIN_HEIGHT * WORLD_SIZE * 2 *
                 ((float)rand() / (float)(RAND_MAX / 1) - 0.5)),
        GREEN);
    blobs.push_back(std::move(food));
  }
}

void Game::update() {
  if (Controls::get_key_state('p')) this->running = true;
  if (!this->running) return;
  // updates
  if (!ended && score < WIN_SCORE) {
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
          this->ended = true;
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

void Game::render() {
  Color textColor = Color(255, 255, 255);
  glPushMatrix();
  glTranslatef(-player->pos.x / 800, -player->pos.y / 800, 0);
  if (!running) {
    Basics::draw_text("Ready?", -0.10, 0.1, textColor);
    Basics::draw_text("Press p to start...", -0.20, 0, textColor);
    Basics::draw_text("Press a to move left", -0.20, -0.1, textColor);
    Basics::draw_text("Press s to move down", -0.20, -0.15, textColor);
    Basics::draw_text("Press d to move right", -0.20, -0.2, textColor);
    Basics::draw_text("Press w to move up", -0.20, -0.25, textColor);
    movement = true;
  } else if (running && !this->ended) {
    if (this->score < WIN_SCORE) {
      if (player) player->render();
      for (size_t i = 0; i < blobs.size(); i++) {
        if (blobs[i]) blobs[i]->render();
      }
      glPopMatrix();
      std::string score = std::to_string(this->score);
      score = std::string("score: ") + score;
      Basics::draw_text(score, 0.75, 0.9, textColor);
    } else {
      glPopMatrix();
      Basics::draw_text("You WIN!!", -0.18, 0, textColor);
      std::string score = std::to_string(this->score);
      std::string text = "Score: " + score;
      Basics::draw_text(text, -0.18, -0.20, textColor);
      movement = false;
    }
  } else {
    glPopMatrix();
    Basics::draw_text("Game OVER!", -0.18, 0, textColor);
    std::string score = std::to_string(this->score);
    std::string text = "Score: " + score;
    Basics::draw_text(text, -0.18, -0.20, textColor);
    return;
  }
  glPopMatrix();
}