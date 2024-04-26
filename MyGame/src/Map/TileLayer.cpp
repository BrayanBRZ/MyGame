#include "TileLayer.h"

TileLayer::TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TilesetList tilesets)
{
    m_Tilesets = tilesize;
    m_RowCount = rowcount;
    m_ColCount = colcount;
    m_TileMap = tilemap;
    m_Tilesets = tilesets;
}

virtual void Render()
{

}

virtual void Update()
{

}