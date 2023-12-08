#include "Player.h"

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
  if (Controls::get_key_state('w')) {
    acc += Vec2(0, 1);
  }
  if (Controls::get_key_state('s')) {
    acc += Vec2(0, -1);
  }
  if (Controls::get_key_state('d')) {
    acc += Vec2(1, 0);
  }
  if (Controls::get_key_state('a')) {
    acc += Vec2(-1, 0);
  }
  if (acc.x != 0 && acc.y != 0) acc *= (1 / acc.norm()) * PLAYER_ACCELERATION;
  this->velocity += acc;

  // update position
  // make sure these are loaded from game
  int window_size_x = game.get_window_x();
  int window_size_y = game.get_window_y();

  Vec2 pos_next = this->pos + this->velocity;

  // hit walls
  if (pos_next.x + this->radius > window_size_x / 2) {
    pos_next.x = window_size_x / 2 - this->radius;
    this->velocity.x = 0;
  }
  if (pos_next.x - this->radius < -window_size_x / 2) {
    pos_next.x = - window_size_x / 2 + this->radius;
    this->velocity.x = 0;
  }
  if (pos_next.y + this->radius > window_size_y / 2) {
    pos_next.y = window_size_y / 2 - this->radius;
    this->velocity.y = 0;
  }
  if (pos_next.y - this->radius < -window_size_y / 2) {
    pos_next.y = - window_size_y / 2 + this->radius;
    this->velocity.y = 0;
  }

  this->pos = pos_next;
}

void Player::render() {
  Basics::DrawCircle(this->pos.x, this->pos.y, this->radius, this->color);
}