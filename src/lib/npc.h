#ifndef NPC_H
#define NPC_H

#include <GL/gl.h>
#include <GL/glut.h>

class NPC {
public:
    NPC();
    ~NPC();

    void drawCircle(float radius);
    void displayCircle();
    void move();

private:
    float npcX;
    float npcY;
};

#endif // NPC_H
