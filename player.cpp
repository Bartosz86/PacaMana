#include <stdio.h>
#include <cstdlib>

#include "player.h"
#include "loaderOBJ.h"

#define mPlayer "modeleBlend/pacman.obj"

using namespace glm;

Player::Player()
{
    bool res = loadOBJ(mPlayer, this->TEMPvertices, this->TEMPuvs, this->TEMPnormals,this->TEMPvCount);
    if(!res)
    {
        printf("Nie uda�o si� wczyta�!");
        exit(1);
    }
    position = vec3(1.0,1.0,1.0);
    rotation = vec3(0.0,0.0,0.0);
    scale = vec3(1.0,1.0,1.0);
    speed = 2;
}

Player::~Player()
{
    TEMPvertices.clear();
    TEMPuvs.clear();
    TEMPnormals.clear();
}

void Player::drawSolid(GLuint &tex,mat4 &V)
{
    glEnable(GL_NORMALIZE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glBindTexture(GL_TEXTURE_2D,tex);

    mat4 M=mat4(1.0f);
    M=translate(M,this->position);
    M=rotate(M,this->rotation.x,vec3(1.0,0.0,0.0));
    glLoadMatrixf(value_ptr(V*M));

    glVertexPointer(3,GL_FLOAT,0,&(this->TEMPvertices[0]));
    glNormalPointer(GL_FLOAT,sizeof(float)*3,&(this->TEMPnormals[0]));
    glTexCoordPointer(2,GL_FLOAT,0,&(this->TEMPuvs[0]));

    float ambient[] = {0,0,0,1};
    float emision[] = {0,0,0,1};
    float diffuse[] = {0.7,0.5,0.5,1};
    float specular[] = {0.5,0.5,0.5,1};
    float shininess = 50;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emision);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glDrawArrays(GL_TRIANGLES,0,this->TEMPvCount);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
