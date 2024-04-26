#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <SDL.h>
#include <string>
#include <map>
#include <string_view>

class TextureManager
{
public:
    std::map<std::string, SDL_Texture *> m_TextureMap;

public:
    static TextureManager *GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new TextureManager(); }
    ~TextureManager();

    bool Load(std::string id, std::string filename);
    void Drop(std::string id);

    SDL_Texture *FindTexture(std::string id);
    // string_view

    void Draw(std::string id, float x, float y, int widht, int height);
    void DrawFrame(std::string id, float x, float y, float objectWidth, float objectHeigth, float spriteWidth, float spriteHeigth, int row, int frame   );
    
    void CleanTexture();

private:
    TextureManager(){};
    static TextureManager *s_Instance;
};

#endif // __TEXTURE_MANAGER_H__