#include "Controls.h"

namespace Controls {
std::map<unsigned char, bool> key_states;

void keypress_cb(unsigned char key, int, int) { key_states[key] = 1; }

void keyup_cb(unsigned char key, int, int) { key_states[key] = 0; }
}  // namespace Controls