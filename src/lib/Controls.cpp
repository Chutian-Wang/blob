#include "Controls.h"
#include "Game.h"

#include <iostream>

Game game;

namespace Controls {
std::map<unsigned char, bool> key_states;

void keypress_cb(unsigned char key, int, int) {
  std::cout << key << std::endl;
  key_states[key] = 1;

  if (key == 's') {
    game.start_game();
  }
}

void keyup_cb(unsigned char key, int, int) { key_states[key] = 0; }

bool get_key_state(unsigned char key) { return key_states[key]; }
}  // namespace Controls