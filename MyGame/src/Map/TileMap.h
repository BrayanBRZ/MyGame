#ifndef __TILEMAP_H__
#define __TILEMAP_H__

#include <vector>
#include <string>

using TileMap = std::vector<std::vector<int>>;

class Map
{
public:
    Map();
    void Render();
    // void Update();

private:
    TileMap m_TileMap;
    std::vector<TileMap> m_TileMapList;

    std::string m_TextureID;
    int m_CurrentMap;
    const int m_SpriteTileSize = 32;
    const int m_ScaleTileSize = 64;
};

#endif // __TILEMAP_H__