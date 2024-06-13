#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Character.h"
#include "..\Graphics\TextureManager.h"
#include "..\Animations\Animation.h"
#include "..\Physics\RigidBody.h"

#include <string>

enum Direction { STAND_BY, Direction_UP, Direction_DOWN, Direction_LEFT, Direction_RIGHT };

class Player: public Character
{
public:
    Player(const Properties& props);    
    ~Player();

    virtual void Draw();
    virtual void Update(float dt);
    void Moviment();

private:
    textureID m_TextureID;
    Direction m_Direction;

    Animation m_Animation;
    RigidBody m_RigidBody;
};

#endif //__PLAYER_H__