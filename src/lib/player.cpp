#include "player.h"

#include "Basics.h"
#include "Controls.h"
#include "Game.h"
#include "Vec2.h"
#include "map"

void Player::update(Game& game) {
  // hadle keyboard inputs
  // make sure this is loaded from game

  // update velocity
  Vec2 acc;
  if (Controls::key_states['w']) {
    acc += Vec2(0, 1);
  }
  if (Controls::key_states['s']) {
    acc += Vec2(0, -1);
  }
  if (Controls::key_states['d']) {
    acc += Vec2(1, 0);
  }
  if (Controls::key_states['a']) {
    acc += Vec2(-1, 0);
  }
  acc *= (1 / acc.norm()) * PLAYER_ACCELERATION;
  this->velocity += acc;

  // update position
  // make sure these are loaded from game
  int window_size_x = game.get_window_x();
  int window_size_y = game.get_window_y();

  Vec2 pos_next = this->pos + this->velocity;

  // hit walls
  if (pos_next.x + this->radius > window_size_x) {
    pos_next.x = window_size_x - this->radius;
    this->velocity.x = 0;
  }
  if (pos_next.x - this->radius < 0) {
    pos_next.x = this->radius;
    this->velocity.x = 0;
  }
  if (pos_next.y + this->radius > window_size_y) {
    pos_next.y = window_size_y - this->radius;
    this->velocity.y = 0;
  }
  if (pos_next.y - this->radius < 0) {
    pos_next.y = this->radius;
    this->velocity.y = 0;
  }

  this->pos = pos_next;
}

void Player::render() {
  Basics::DrawCircle(this->pos.x, this->pos.y, this->radius, this->color);
}