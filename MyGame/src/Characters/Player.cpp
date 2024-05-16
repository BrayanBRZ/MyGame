#include "Player.h"
#include "..\Events\Event.h"
#include <SDL.h>

Player::Player(const Properties& props) : Character(props)
{ 
    m_TextureID = TextureManager::GetInstance()->Load("../assets/player/red.png");

    m_Animation = new Animation();
    m_RigidBody = new RigidBody();
    
    m_RigidBody->SetFriction(0.8f);
    m_RigidBody->ApplyForceX(0.0f);
    m_RigidBody->ApplyForceY(0.0f);

    m_Direction = Direction_DOWN;

}

Player::~Player(){
    TextureManager::GetInstance()->CleanTexture();
}

void Player::Draw()
{
    m_Animation->Draw(m_Position.x, m_Position.y, m_Width, m_Height);
}

void Player::Update(float dt)
{
    m_RigidBody->ApplyForceX(m_RigidBody->Acceleration().x);
    m_RigidBody->ApplyForceY(m_RigidBody->Acceleration().y);
    Player::Moviment();
    m_RigidBody->Update(dt, m_Position);
    m_Animation->Update();
}

void Player::Moviment()
{
    // Stand By
    if (this->m_Direction == Direction_UP)
    { m_Animation->SetProps(m_TextureID, 4, 1, 200, 64, 64); }

    if (this->m_Direction == Direction_DOWN)
    { m_Animation->SetProps(m_TextureID, 1, 1, 200, 64, 64); }

    if (this->m_Direction == Direction_LEFT)
    { m_Animation->SetProps(m_TextureID, 2, 1, 200, 64, 64); }

    if (this->m_Direction == Direction_RIGHT)
    { m_Animation->SetProps(m_TextureID, 3, 1, 200, 64, 64); }

    // Animation
    if (Event::GetInstance()->GetKeyDown(SDL_SCANCODE_W))
    {
        if (!(Event::GetInstance()->GetKeyDown(SDL_SCANCODE_S)))
            { this->m_Direction = Direction_UP; m_Animation->SetProps(m_TextureID, 4, 4, 200, 64, 64);}
        m_RigidBody->ApplyForceY(m_RigidBody->m_Force.y + (1.5 * UPWARD));
    }

    if (Event::GetInstance()->GetKeyDown(SDL_SCANCODE_S))
    {
        if (!(Event::GetInstance()->GetKeyDown(SDL_SCANCODE_W)))
            { this->m_Direction = Direction_DOWN; m_Animation->SetProps(m_TextureID, 1, 4, 200, 64, 64); }
        m_RigidBody->ApplyForceY(m_RigidBody->m_Force.y + (1.5 * DOWNWARD));
    }

    if (Event::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
    {
        if (!(Event::GetInstance()->GetKeyDown(SDL_SCANCODE_D)))
            { this->m_Direction = Direction_LEFT; m_Animation->SetProps(m_TextureID, 2, 4, 200, 64, 64); }
        m_RigidBody->ApplyForceX(m_RigidBody->m_Force.x + (1.5 * LEFTWARD));
    }

    if (Event::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
    {
        if (!(Event::GetInstance()->GetKeyDown(SDL_SCANCODE_A)))
            { this->m_Direction = Direction_RIGHT; m_Animation->SetProps(m_TextureID, 3, 4, 200, 64, 64); }
        m_RigidBody->ApplyForceX(m_RigidBody->m_Force.x + (1.5 * RIGHTWARD));
    }
}