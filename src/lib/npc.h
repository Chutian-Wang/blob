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
    float directionX;
    float directionY;
    float speed = 0.04; // Adjust the speed as needed
};

#endif // NPC_H
