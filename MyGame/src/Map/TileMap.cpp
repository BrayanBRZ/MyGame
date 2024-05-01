#include "TileMap.h"
#include "../Graphics/TextureManager.h"

TileMap lvl1 = {
    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
    {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {3, 0, 0, 2, 2, 2, 2, 0, 0, 3},
    {3, 0, 0, 2, 1, 1, 2, 0, 0, 3},
    {3, 0, 0, 2, 1, 1, 2, 0, 0, 3},
    {3, 0, 0, 2, 2, 2, 2, 0, 0, 3},
    {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {3, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}};

Map::Map()
{
    TextureManager::GetInstance()->Load("map", "../assets/maps/basic-terrain.png");
    m_TextureID = "map";
    m_CurrentMap = 0;
    m_TileMapList.push_back(lvl1);
}

void Map::Render()
{

    int row = lvl1.size();
    int column = lvl1[0].size();

    for (int x = 0; x < row; ++x)
    {
        for (int y = 0; y < column; ++y)
        {
            int tileID = lvl1[x][y];

            switch (tileID)
            {
            case 0: TextureManager::GetInstance()->DrawFrame(m_TextureID, (x * m_ScaleTileSize), (y * m_ScaleTileSize), m_ScaleTileSize, m_ScaleTileSize, m_SpriteTileSize, m_SpriteTileSize, (0 + 1), 0);
                break;

            case 1: TextureManager::GetInstance()->DrawFrame(m_TextureID, (x * m_ScaleTileSize), (y * m_ScaleTileSize), m_ScaleTileSize, m_ScaleTileSize, m_SpriteTileSize, m_SpriteTileSize, (0 + 1), 1);
                break;
            
            case 2: TextureManager::GetInstance()->DrawFrame(m_TextureID, (x * m_ScaleTileSize), (y * m_ScaleTileSize), m_ScaleTileSize, m_ScaleTileSize, m_SpriteTileSize, m_SpriteTileSize, (1 + 1), 0);
                break;

            case 3: TextureManager::GetInstance()->DrawFrame(m_TextureID, (x * m_ScaleTileSize), (y * m_ScaleTileSize), m_ScaleTileSize, m_ScaleTileSize, m_SpriteTileSize, m_SpriteTileSize, (1 + 1), 1);
                break;
            }
        }
    }
}