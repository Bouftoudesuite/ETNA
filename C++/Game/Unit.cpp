#include "Unit.hh"

Unit::Unit(const int x, const int y, Player& player) : _x(x), _y(y), _player(player)
{}

int Unit::getX() const
{
    return (_x);
}

int Unit::getY() const
{
    return (_y);
}

Player& Unit::getOwner()
{
    return (_player);
}
