#include "Map.hh"
#include "CellProperty.hh"
#include "CellType.hh"

int getCellFlags(CellType type)
{
    if (type == GrassCell)
        return (SWIMMABLE | FLYABLE);
    else if (type == WaterCell)
        return (SWIMMABLE | WALKABLE);
    else if (type == RockCell)
        return (FLYABLE);
    else if (type == MountainCell)
        return (NO_FLAG);
    return (NO_FLAG);
}

CellProperty::CellProperty() :
    _walkable(false),
    _swimmable(false),
    _flyable(false),
    _event(false),
    _monster(false)
{}

CellProperty::CellProperty(CellType newCellType) :
    _walkable(false),
    _swimmable(false),
    _flyable(false),
    _event(false),
    _monster(false)
{
    if (CellProperty::getCellFlags(newCellType) == FLYABLE)
        _flyable = true;
    else if (CellProperty::getCellFlags(newCellType) == WALKABLE)
        _walkable = true;
    else if (CellProperty::getCellFlags(newCellType) == SWIMMABLE)
        _swimmable = true;
    else if (CellProperty::getCellFlags(newCellType) == (FLYABLE | WALKABLE)
    {
        _flyable = true;
        _walkable = true;
    }
    else if (CellProperty::getCellFlags(newCellType) == (SWIMMABLE | FLYABLE))
    {
        _swimmable = true;
        _flyable = true;
    }
    else if (CellProperty::getCellFlags(newCellType) == (SWIMMABLE | WALKABLE))
    {
        _swimmable = true;
        _walkable = true;
    }
    else if (CellProperty::getCellFlags(newCellType) == (SWIMMABLE | WALKABLE | FLYABLE))
    {
        _swimmable = true;
        _walkable = true;
        _flyable = true;
    }
}

bool CellProperty::isWalkable() const
{
    return (_walkable);
}
bool CellProperty::isSwimmable() const
{
    return (_swimmable);
}
bool CellProperty::isFlyable() const
{
    return (_flyable);
}
bool CellProperty::isEvent() const
{
    return (_event);
}
bool CellProperty::isMonster() const
{
    return (_monster);
}
void CellProperty::setWalkable()
{
    _walkable = true;
}
void CellProperty::setNotWalkable()
{
    _walkable = false;
}
void CellProperty::setSwimmable()
{
    _swimmable = true;
}
void CellProperty::setNotSwimmable()
{
    _swimmable = false;
}

void CellProperty::setFlyable()
{
    _flyable = true;
}

void CellProperty::setNotFlyable()
{
    _flyable = false;
}

void CellProperty::setEvent()
{
    _event = true;
}

void CellProperty::setNotEvent()
{
    _event = false;
}

void CellProperty::setMonster()
{
    _monster = true;
}

void CellProperty::setNotMonster()
{
    _monster = false;
}

bool operator==(CellProperty const& a, CellProperty const& b)
{
    return (a._walkable == b._walkable && a._swimmable == b._swimmable
        && a._flyable == b._flyable && a._event == b._event
        && a._monster == b._monster);
}

bool operator!=(CellProperty const& a, CellProperty const& b)
{
    return (a._walkable != b._walkable || a._swimmable != b._swimmable
        || a._flyable != b._flyable || a._event != b._event
        || a._monster != b._monster);
}
