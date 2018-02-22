#include "Hero.hh"
#include <iostream>

UnitField Hero::getField() const
{
    return (Ground);
}

unsigned int Hero::getCost() const
{
    return (8000);
}

unsigned int Hero::getAttackRange() const
{
    return (1);
}

unsigned int Hero::getAttackMinRange() const
{
    return (1);
}

unsigned int Hero::getAttackArea() const
{
    return (1);
}

Stats const& Hero::getBaseStats()
{
    static Stats stats {2000, 30, 6, 3, 2000, 30, 6, 3};
    return (stats);
}

void Hero::resetStats()
{
    static Stats stats {0, 0, 0, 0, 0, 0, 0, 0};

    stats = getBaseStats();
    setHp(stats._hp);
    setPp(stats._pp);
    setAp(stats._ap);
    setMp(stats._mp);
    setHpMax(stats._hpMax);
    setPpMax(stats._ppMax);
    setApMax(stats._apMax);
    setMpMax(stats._mpMax);
}

void Hero::resetActions()
{
    static Stats stats {0, 0, 0, 0, 0, 0, 0, 0};

    stats = getBaseStats();
    setAp(stats._ap);
    setMp(stats._mp);
}

bool Hero::load(const std::string& tileset, sf::Vector2u tileSize, int width, int height)
{
    int i = getX();
    int j = getY();

    if (!_tileset.loadFromFile(tileset))
    {
        return (false);
    }

    _vertices.setPrimitiveType(sf::Quads);
    _vertices.resize(width * height * 4);

    int tileNumber = std::rand() % 4 + 1;
    if (tileNumber == 2)
    {
        tileNumber = 31;
    }
    else if (tileNumber == 3)
    {
        tileNumber = 28;
    }

    int tu = tileNumber % (_tileset.getSize().x / tileSize.x);
    int tv = tileNumber / (_tileset.getSize().x / tileSize.x);

    sf::Vertex *quad = &_vertices[(i + j * width) * 4];

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