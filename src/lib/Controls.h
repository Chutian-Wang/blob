#ifndef CONTROLS_H
#define CONTROLS_H

#include <GL/gl.h>
#include <GL/glut.h>

#include <map>

namespace Controls {
std::map<unsigned char, bool> key_states;

void keypress_cb(unsigned char key, int, int) { key_states[key] = 1; }

void keyup_cb(unsigned char key, int, int) { key_states[key] = 0; }
}  // namespace Controls

#endif  // CONTROLS_H