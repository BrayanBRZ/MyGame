#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Character.h"
#include "..\Animations\Animation.h"
#include "..\Physics\RigidBody.h"

#include <string>

enum Direction { STAND_BY, Direction_UP, Direction_DOWN, Direction_LEFT, Direction_RIGHT };

class Player: public Character
{
public:
    Player(const Properties& props, std::string TextureID);
    ~Player();
    
    virtual void Draw() override;
    virtual void Update(float dt) override;
    void Moviment();

private:
    std::string m_TextureID;
    Animation* m_Animation;
    RigidBody* m_RigidBody;
    Direction m_Direction;
};


#endif //__PLAYER_H__