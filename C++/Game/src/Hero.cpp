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

void Hero::turn(Direction direction)
{
    if ((_tileNumber >= 0 && _tileNumber <= 2) || (_tileNumber >= 9 && _tileNumber <= 11)|| (_tileNumber >= 18 && _tileNumber <= 20))
    {
        switch (direction)
        {
            case North:
                _tileNumber = 19;
                break;

            case South:
                _tileNumber = 1;
                break;

            case East:
                _tileNumber = 10;
                break;

            case West:
                _tileNumber = 10;
                break;
        }
    }
    else if ((_tileNumber >= 3 && _tileNumber <= 5) || (_tileNumber >= 12 && _tileNumber <= 14)|| (_tileNumber >= 21 && _tileNumber <= 23))
    {
        switch (direction)
        {
            case North:
                _tileNumber = 22;
                break;

            case South:
                _tileNumber = 4;
                break;

            case East:
                _tileNumber = 13;
                break;

            case West:
                _tileNumber = 13;
                break;
        }
    }
    else if ((_tileNumber >= 27 && _tileNumber <= 29) || (_tileNumber >= 36 && _tileNumber <= 38)|| (_tileNumber >= 45 && _tileNumber <= 47))
    {
        switch (direction)
        {
            case North:
                _tileNumber = 46;
                break;

            case South:
                _tileNumber = 28;
                break;

            case East:
                _tileNumber = 37;
                break;

            case West:
                _tileNumber = 37;
                break;
        }
    }
    else if ((_tileNumber >= 30 && _tileNumber <= 32) || (_tileNumber >= 39 && _tileNumber <= 41)|| (_tileNumber >= 48 && _tileNumber <= 50))
    {
        switch (direction)
        {
            case North:
                _tileNumber = 49;
                break;

            case South:
                _tileNumber = 31;
                break;

            case East:
                _tileNumber = 40;
                break;

            case West:
                _tileNumber = 40;
                break;
        }
    }
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

    _tileNumber = (unsigned int)std::rand() % 4 + 1;
    if (_tileNumber == 2)
    {
        _tileNumber = 31;
    }
    else if (_tileNumber == 3)
    {
        _tileNumber = 28;
    }

    unsigned int tu = _tileNumber % (_tileset.getSize().x / tileSize.x);
    unsigned int tv = _tileNumber / (_tileset.getSize().x / tileSize.x);

    _quad = &_vertices[(i + j * width) * 4];

    _quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
    _quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
    _quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
    _quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

    _quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
    _quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
    _quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
    _quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

    return (true);
}

bool Hero::reload(const std::string& tileset, sf::Vector2u tileSize, int width, int height)
{
    int i = getX();
    int j = getY();

    if (!_tileset.loadFromFile(tileset))
    {
        return (false);
    }

    unsigned int tu = _tileNumber % (_tileset.getSize().x / tileSize.x);
    unsigned int tv = _tileNumber / (_tileset.getSize().x / tileSize.x);

    _quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
    _quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
    _quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
    _quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

    _quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
    _quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
    _quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
    _quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

    return (true);
}