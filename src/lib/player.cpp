#include "player.h"

Player::Player(float radius, Vec2 pos, Vec2 velocity, Color color){
    this->radius   = radius;
    this->pos      = pos;
    this->velocity = velocity;
    this->color    = color;
}