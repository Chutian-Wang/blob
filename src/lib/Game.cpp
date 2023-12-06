#include <vector>
#include "player.h"
#include "NPC.h"
#include "Game.h"

Game::Game(){
    player = Player(3, Vec2(10, 10), Vec2(1, 1), Color(255, 0, 0));
    blobs.push_back(player);
    for (int i = 0; i<NPC_AMOUNT; i++){
        NPC npc = NPC(3, Vec2(10, 10), Vec2(1, 1), Color(0, 255, 0));
        blobs.push_back(npc);
    }
    for (int i = 0; i<FOOD_AMOUNT; i++){
        Food food = Food(1, Vec2(10, 10), Vec2(1, 1), Color(0, 0, 255));
        blobs.push_back(food);
    }
}

Game::~Game(){
}

void Game::update(){
    std::vector<Blob> survivors;
    
    for(size_t i = 0; i < blobs.size(); ++i) {
        blobs[i].update();
        for(size_t j = 0; j < i; ++ j) {
            if((blobs[i].get_pos()-blobs[j].get_pos()).x < blobs[i].get_radius()) {
                blobs[j].set_survive(false);
            }
        }
    }

    for(Blob blob: blobs) {
        if(!blob.get_survive()) {
            // blob -> update();
            survivors.push_back(blob);
        }
    }

    blobs = survivors;
}

void Game::start_game(){
    start = true;
    update();
}

void Game::render(){
    for (int i = 0; i < blobs.size(); i++){
        blobs[i] -> render();
    }
}