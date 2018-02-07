#include "Unit.hh"

Unit::Unit(const int x, const int y) : _x(x), _y(y)
{}

UnitField Unit::getField() const
{
    return (Ground);
}
