#ifndef tilemap_hpp
#define tilemap_hpp

#include "SceneNode.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics.hpp>

#include <vector>


namespace eng
{

class TileMap: public SceneNode
{
public:
                                TileMap(const TextureHolder& textures, sf::FloatRect worldBounds);

    bool                        load(sf::Vector2u tileSize, unsigned int width, unsigned int height);
    void                        refresh();
    void                        createVertexArray();

private:
    sf::Vector2u                mSize;
    sf::Vector2u                mTileSize;
    std::vector<int>            mTiles;

    sf::VertexArray             mVertices;
    sf::Texture                 mTileset;

    sf::FloatRect               mWorldBounds;

private:
    virtual void                drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif
