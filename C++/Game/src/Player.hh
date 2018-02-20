#ifndef _PLAYER_HH_
# define _PLAYER_HH_

#include <SFML/Graphics.hpp>
#include <string>

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player(std::string const& name, int budget);
    ~Player();
    int getX() const;
    int getY() const;
    int getBudget() const;
    const std::string& getName() const;
    void setX(int x);
    void setY(int y);
    void setBudget(int budget);
    bool load(const std::string& tileset, sf::Vector2u tileSize, int width, int height);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    int _x;
    int _y;
    std::string _name;
    int _budget;
    sf::VertexArray _vertices;
    sf::Texture _tileset;
};

#endif
