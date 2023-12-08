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
  this->pos += velocity;

  // Hit walls
  if (this->pos.x + this->radius > game.get_window_x()) {
    this->pos.x = game.get_window_x() - this->radius;
    this->velocity.x = 0;
  }
  if (this->pos.x - this->radius < 0) {
    this->pos.x = this->radius;
    this->velocity.x = 0;
  }
  if (this->pos.y + this->radius > game.get_window_y()) {
    this->pos.y = game.get_window_y() - this->radius;
    this->velocity.y = 0;
  }
  if (this->pos.y - this->radius < 0) {
    this->pos.y = this->radius;
    this->velocity.y = 0;
  }
}

void Food::render() {
  Basics::DrawCircle(this->pos.x, this->pos.y, this->radius, this->color);
}