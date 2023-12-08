#ifndef CONTROLS_H
#define CONTROLS_H

#include <GL/gl.h>
#include <GL/glut.h>

#include <map>

namespace Controls {
extern std::map<unsigned char, bool> key_states;

void keypress_cb(unsigned char key, int, int);

void keyup_cb(unsigned char key, int, int);

bool get_key_state(unsigned char key);
}  // namespace Controls

#endif  // CONTROLS_H