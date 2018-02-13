#include <algorithm>
#include "Game.hh"

bool Game::canPlaceUnit(int x, int y, Unit const& unit)
{
    unsigned int i;
    UnitField field;

    i = 0;
    field = unit.getField();
    while (i < _units.size())
    {
        if (_units[i]->getField() == field && _units[i]->getX() == x && _units[i]->getY() == y)
            return (false);
        i++;
    }
    return (_map.canGo(x, y, unit));
}

bool Game::placeUnit(Unit* unit)
{
    if (canPlaceUnit(unit->getX(), unit->getY(), *unit))
    {
        _units.push_back(unit);
        return (true);
    }
    return (false);
}

bool Game::addUnit(Unit* unit)
{
    if (unit->getOwner().getBudget() >= unit->getCost())
    {
        if (placeUnit(unit))
        {
            unit->getOwner().setBudget(unit->getOwner().getBudget() - unit->getCost());
            return (true);
        }
    }
    return (false);
}

void Game::resetUnits()
{
    unsigned int i;

    i = 0;
    while (i < _units.size())
    {
        _units[i]->resetStats();
        i++;
    }
}

void Game::newTurn()
{
    unsigned int i;

    i = 0;
    _units.erase(std::remove_if(_units.begin(), _units.end(), my_predicate), _units.end());
    while (i < _units.size())
    {
        _units[i]->resetStats();
        i++;
    }
}

bool Game::didLose(Player const& player)
{
    unsigned int i;

    i = 0;
    while (i < _units.size())
    {
        if (_units[i]->getOwner().getName() == player.getName())
            return (false);
        i++;
    }
    return (true);
}


bool my_predicate(const Unit& item)
{
    return (item.getHp() <= 0);
}