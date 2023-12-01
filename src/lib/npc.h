#ifndef NPC_H
#define NPC_H

#include <GL/gl.h>
#include <GL/glut.h>

class NPC {
    private:
    NPC();
    ~NPC();

    float npcX;
    float npcY;

    public:
    static NPC& getInstance();

    void drawCircle(float radius);
    void displayCircle();
    void move();
};

#endif