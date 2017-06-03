#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "model.h"
#include "map.h"

class Player: public Model
{
public:
    Player(Map* &mapa);
    ~Player();
    void drawSolid(GLuint &tex,mat4 &V);
private:
    findPosition(Map* &mapa);
};

#endif // PLAYER_H_INCLUDED
