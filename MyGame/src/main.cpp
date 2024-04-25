#include "Core\Engine.h"
#include "Timer\timer.h"

/* g++ main.cpp Core/Engine.cpp Graphics/TextureManager.cpp Characters/Player.cpp Animations/Animation.cpp
Events/Event.cpp Timer/timer.cpp -o main.exe -std=c++23 -I/ucrt64/include/SDL2 -I/home/braya/my-lib/include
-Dmain=SDL_main -L/ucrt64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image */

int main(int argc, char *argv[]){

    Engine::GetInstance()->Init();


    while (Engine::GetInstance()->isRunning()){
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
        Timer::GetInstance()->Tick();
    }

    Engine::GetInstance()->CleanGame();
    
    return 0;
}