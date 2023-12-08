#include "NPC.h"

#include "Basics.h"
#include "Blob.h"
#include "Game.h"

void NPC::render() {
  Basics::DrawCircle(this->pos.x, this->pos.y, this->radius, this->color);
}

void NPC::update(Game& game) {
  Vec2 player_pos = game.get_player()->pos;
  float player_size = game.get_player()->radius;
  auto& blobs = game.get_blobs();

  // Move away from bigger blobs and move towards smaller blobs
  // 1/dis makes influence grater for closer blobs and make the
  // NPC appear dumber
  Vec2 force = (player_pos - this->pos) * (1 / (player_pos - this->pos).norm());
  if (player_size >= this->radius) force.negate();

  for (auto& blob : blobs) {
    // null elimination
    if (!blob) continue;
    // No self evaluation
    if (blob.get() == this) continue;

    force +=
        (blob->radius < this->radius)
            ? (blob->pos - this->pos) * (1 / (blob->pos - this->pos).norm())
            : ((blob->pos - this->pos) * (1 / (blob->pos - this->pos).norm()))
                  .negate();
  }
  force = force.normalize() * NPC_ACCELERATION;

  // Discrete integration
  this->velocity += force;
  if (this->velocity.norm() > NPC_MAX_SPEED) {
    this->velocity = this->velocity.normalize() * NPC_MAX_SPEED;
  }

  // Hit walls

  int window_size_x = game.get_window_x();
  int window_size_y = game.get_window_y();

  Vec2 pos_next = this->pos + this->velocity;

  if (pos_next.x + this->radius > window_size_x) {
    pos_next.x = window_size_x - this->radius;
    this->velocity.x = 0;
  }
  if (pos_next.x - this->radius < -window_size_x) {
    pos_next.x = -window_size_x + this->radius;
    this->velocity.x = 0;
  }
  if (pos_next.y + this->radius > window_size_y) {
    pos_next.y = window_size_y - this->radius;
    this->velocity.y = 0;
  }
  if (pos_next.y - this->radius < -window_size_y) {
    pos_next.y = -window_size_y + this->radius;
    this->velocity.y = 0;
  }

  this->pos = pos_next;
}

void Food::render() {
  Basics::DrawCircle(this->pos.x, this->pos.y, this->radius, this->color);
}