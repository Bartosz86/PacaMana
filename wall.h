#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "model.h"

class Wall: public Model {
public:
    Wall(colision_length &colision_length);
    ~Wall();
    void drawSolid(GLuint &tex,mat4 &V);
};


#endif // WALL_H_INCLUDED
