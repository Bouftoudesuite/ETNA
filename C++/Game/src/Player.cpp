#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Player.hh"

Player::Player(std::string const& name, int budget) : _name(name), _budget(budget), _x(0), _y(0)
{}

Player::~Player()
{}

int Player::getX() const
{
    return (_x);
}
int Player::getY() const
{
    return (_y);
}

int Player::getBudget() const
{
    return (_budget);
}

const std::string& Player::getName() const
{
    return (_name);
}

void Player::setX(int x)
{
    _x = x;
}

void Player::setY(int y)
{
    _y = y;
}

void Player::setBudget(int budget)
{
    _budget = budget;
}

bool Player::load(const std::string& tileset, sf::Vector2u tileSize, int width, int height)
{
    int i = getX();
    int j = getY();

    if (!_tileset.loadFromFile(tileset))
    {
        return (false);
    }

    _vertices.setPrimitiveType(sf::Quads);
    _vertices.resize(width * height * 4);

    int tileNumber = rand()%4+1;
    if (tileNumber == 2)
    {
        tileNumber = 31;
    }
    if (tileNumber == 3)
    {
        tileNumber = 28;
    }

    int tu = tileNumber % (_tileset.getSize().x / tileSize.x);
    int tv = tileNumber / (_tileset.getSize().x / tileSize.x);

    sf::Vertex* quad = &_vertices[(i + j * width) * 4];

    quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
    quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
    quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
    quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

    quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
    quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
    quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
    quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

    return (true);
}


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &_tileset;
    target.draw(_vertices, states);
}
