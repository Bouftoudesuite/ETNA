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
{}

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
    return (this->_event)
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
