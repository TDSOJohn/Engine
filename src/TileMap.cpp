#include "TileMap.hpp"
#include "Category.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <iostream>


namespace eng
{

TileMap::TileMap(const TextureHolder& textures, sf::FloatRect worldBounds):
    SceneNode(Category::Background),
    mWorldBounds(worldBounds),
    mTileset(textures.get(Textures::ID::Tileset))
{
}

bool TileMap::load(sf::Vector2u tileSize)
{
    mSize = {static_cast<unsigned int>(mWorldBounds.width / tileSize.x), static_cast<unsigned int>(mWorldBounds.height / tileSize.y)};
    mTileSize = tileSize;

    for(int i = 0; i < mSize.x; i++)
    {
        for(int j = 0; j < mSize.y; j++)
            mTiles.push_back(rand()%4);
    }
    // resize the vertex array to fit the level size
    mVertices.setPrimitiveType(sf::Quads);
    mVertices.resize(mSize.x * mSize.y * 4);

    refresh();

    return true;
}

void TileMap::refresh()
{
    // Generate new random tiles
    for(int i = 0; i < (mSize.x * mSize.y); i++)
        mTiles[i] = rand() % 4;

    createVertexArray();
}

void TileMap::createVertexArray()
{
    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < mSize.x; ++i)
    {
        for (unsigned int j = 0; j < mSize.y; ++j)
        {
            // get the current tile number
            int tileNumber = mTiles[i + j * mSize.x];

            // find its position in the tileset texture
            int tu = tileNumber % (mTileset.getSize().x / mTileSize.x);
            int tv = tileNumber / (mTileset.getSize().x / mTileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &mVertices[(i + j * mSize.x) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * mTileSize.x, j * mTileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * mTileSize.x, j * mTileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * mTileSize.x, (j + 1) * mTileSize.y);
            quad[3].position = sf::Vector2f(i * mTileSize.x, (j + 1) * mTileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * mTileSize.x, tv * mTileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * mTileSize.x, tv * mTileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * mTileSize.x, (tv + 1) * mTileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * mTileSize.x, (tv + 1) * mTileSize.y);
        }
    }
}

void TileMap::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the state transform
    states.transform *= getTransform();
    // apply the tileset texture
    states.texture = &mTileset;

    // draw the vertex array
    target.draw(mVertices, states);
}

}
