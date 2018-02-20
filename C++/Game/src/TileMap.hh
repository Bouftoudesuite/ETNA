#include <SFML/Graphics.hpp>
#include "Map.hh"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, Map map, int width, int height);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::VertexArray _vertices;
    sf::Texture _tileset;
};
