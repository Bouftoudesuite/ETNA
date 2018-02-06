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
    if (Map::getCellFlags(newCellType) == FLYABLE)
        _flyable = true;
    else if (Map::getCellFlags(newCellType) == WALKABLE)
        _walkable = true;
    else if (Map::getCellFlags(newCellType) == SWIMMABLE)
        _swimmable = true;
    else if (Map::getCellFlags(newCellType) == (FLYABLE | WALKABLE)
    {
        _flyable = true;
        _walkable = true;
    }
    else if (Map::getCellFlags(newCellType) == (SWIMMABLE | FLYABLE))
    {
        _swimmable = true;
        _flyable = true;
    }
    else if (Map::getCellFlags(newCellType) == (SWIMMABLE | WALKABLE))
    {
        _swimmable = true;
        _walkable = true;
    }
    else if (Map::getCellFlags(newCellType) == (SWIMMABLE | WALKABLE | FLYABLE))
    {
        _swimmable = true;
        _walkable = true;
        _flyable = true;
    }
}

bool CellProperty::isWalkable() const
{
    return (this->_walkable);
}
bool CellProperty::isSwimmable() const
{
    return (this->_swimmable);
}
bool CellProperty::isFlyable() const
{
    return (this->_flyable);
}
bool CellProperty::isEvent() const
{
    return (this->_event);
}
bool CellProperty::isMonster() const
{
    return (this->_monster);
}
void CellProperty::setWalkable()
{
    this->_walkable = true;
}
void CellProperty::setNotWalkable()
{
    this->_walkable = false;
}
void CellProperty::setSwimmable()
{
    this->_swimmable = true;
}
void CellProperty::setNotSwimmable()
{
    this->_swimmable = false;
}

void CellProperty::setFlyable()
{
    this->_flyable = true;
}

void CellProperty::setNotFlyable()
{
    this->_flyable = false;
}

void CellProperty::setEvent()
{
    this->_event = true;
}

void CellProperty::setNotEvent()
{
    this->_event = false;
}

void CellProperty::setMonster()
{
    this->_monster = true;
}

void CellProperty::setNotMonster()
{
    this->_monster = false;
}
