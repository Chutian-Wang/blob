#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#include "player.h"
#include "NPC.h"
#include "Game.h"

Game::Game(){
    srand (time(NULL));

    // initialize blobs with random pos
    auto player = std::make_unique<Player>(Player(3, Vec2(rand() % (int)(WIN_WIDTH/2.0f) + WIN_WIDTH/2.0f, rand() % (int)(WIN_HEIGHT/2.0f) + WIN_HEIGHT/2.0f), Vec2(1, 1), RED));
    blobs.push_back(std::move(player));

    for (int i = 0; i<NPC_AMOUNT; i++){
        auto npc = std::make_unique<NPC>(NPC(3, Vec2(rand() % (int)(WIN_WIDTH/2.0f) + WIN_WIDTH/2.0f, rand() % (int)(WIN_HEIGHT/2.0f) + WIN_HEIGHT/2.0f), Vec2(1, 1), BLUE));
        blobs.push_back(std::move(npc));
    }
    for (int i = 0; i<FOOD_AMOUNT; i++){
        auto food = std::make_unique<Food>(Food(1, Vec2(rand() % (int)(WIN_WIDTH/2.0f) + WIN_WIDTH/2.0f, rand() % (int)(WIN_HEIGHT/2.0f) + WIN_HEIGHT/2.0f), Vec2(1, 1), GREEN));
        blobs.push_back(std::move(food));
    }
}

Game::~Game(){}

void Game::update(){
    // implement this later
    for(size_t i = 0; i < blobs.size(); ++i) {
        if (blobs[i]) blobs[i] -> update();

        // check if blob goes outside bound
        if (blobs[i]->get_pos().x - blobs[i]->get_radius() < 0){
            blobs[i]->get_pos().x = blobs[i]->get_radius();
        }
        if (blobs[i]->get_pos().x + blobs[i]->get_radius() > WIN_WIDTH){
            blobs[i]->get_pos().x = WIN_WIDTH - blobs[i]->get_radius();
        }
        if (blobs[i]->get_pos().y - blobs[i]->get_radius() < 0){
            blobs[i]->get_pos().y = blobs[i]->get_radius();
        }
        if (blobs[i]->get_pos().y + blobs[i]->get_radius() > WIN_HEIGHT){
            blobs[i]->get_pos().y = WIN_HEIGHT - blobs[i]->get_radius();
        }

        for(size_t j = 0; j < blobs.size(); ++ j) {
            // check if nullptr
            if (blobs[i] && blobs[j]){
                if((blobs[i]->get_pos()-blobs[j]->get_pos()).norm() < blobs[i]->get_radius()+blobs[j]->get_radius()) {
                    if (blobs[i]->get_radius()<blobs[j]->get_radius()){
                        blobs[i].release();
                        blobs[i] = nullptr;
                        blobs[j] -> update();
                    } else if (blobs[i]->get_radius()>blobs[j]->get_radius()){
                        blobs[j].release();
                        blobs[j] = nullptr;
                        blobs[i] -> update();
                    }
                }
            }
        }
    }
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