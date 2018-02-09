#include "UnitField.hh"
#include "Unit.hh"

Unit::Unit() : _x(0), _y(0)
{}

Unit::Unit(const int x, const int y) : _x(x), _y(y)
{}

int Unit::getX() const
{
    return (_x);
}

int Unit::getY() const
{
    return (_y);
}

UnitField Unit::getField() const
{
    return (Ground);
}
