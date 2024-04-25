#include "Engine.h"
#include "..\Graphics\TextureManager.h"
#include "..\Events\Event.h"
#include "..\Timer\timer.h"
#include "..\Characters\Player.h"

Engine* Engine::s_Instance = nullptr;
Player* player = nullptr;

bool Engine::Init()
{   
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0){
        SDL_Log("Failed to initialize SDL. Error: %s", SDL_GetError());
        return false;
    }

    SDL_Log("CARREGOU A SDL");

    m_Window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEEN_WIDTH, SCREEN_HEIGHT, 0);
    if(m_Window == nullptr) {
        SDL_Log("Failed to create window. Error: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(m_Window == nullptr) {
        SDL_Log("Failed to create Renderer. Error: %s", SDL_GetError());
        return false;
    }

    TextureManager::GetInstance()->Load("player", "../assets/Player/red.png");

    player = new Player(Properties(0, 0, 128, 128), "player");

    return m_isRunning = true;
}

void Engine::Update()
{
    float dt = Timer::GetInstance()->GetDeltaTime();
    player->Update(dt);
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
    SDL_RenderClear(m_Renderer);

    player->Draw();
    SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
    Event::GetInstance()->Listen();
}

bool Engine::CleanGame()
{   
    TextureManager::GetInstance()->CleanTexture();
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(m_Renderer);
    
    IMG_Quit();
    SDL_Quit();
    return 0;
}


void Engine::Quit()
{
    m_isRunning = false;
}   