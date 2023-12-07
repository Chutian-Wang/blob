#include "NPC.h"

#include "Basics.h"

void NPC::render() {
  Basics::DrawCircle(this->pos.x, this->pos.y, this->radius, this->color);
}

void NPC::update(Game& game) {
    Vec2 player_pos = game.get_player().get_pos();
    auto& blobs = game.get_blobs();

    int target_idx = -1;
    float min_dis = (player_pos - this->pos).norm();
    for (size_t i = 0; i < blobs.size(); i++) {
        int dis = (blobs[i].pos - this->pos).norm();
        if (dis < min_dis) {
            target_idx = i;
            min_dis = dis;
        }
    }
    Vec2 error;
    if (target_idx = -1) {
        error = player_pos - this->pos;
    } else {
        error = blobs[target_idx].get_pos() - this->pos;
    }

}

void NPC::render() {
  Basics::DrawCircle(this->pos.x, this->pos.y, this->radius, this->color);
}