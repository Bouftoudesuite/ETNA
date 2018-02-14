#include <exception>
#include <algorithm>
#include <iostream>
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
    std::vector<int> toRemove;
    unsigned int i;

    /* Find what to remove */
    i = 0;
    while (i < _units.size())
    {
        if (_units[i]->getHp() <= 0)
            toRemove.push_back(i - 1);
        i++;
    }

    /* Remove */
    i = 0;
    while (i < toRemove.size())
    {
        _units.erase(_units.begin() + toRemove[i]);
        i++;
    }

    /* Reset */
    i = 0;
    while (i < _units.size())
    {
        _units[i]->resetStats();
        i++;
    }
}

bool my_predicate(const Unit& item)
{
    return (item.getHp() <= 0);
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

void Game::moveUnit(Unit& unit, Direction direction, int n)
{
    int i;
    int j;
    int tmp_x;
    int tmp_y;
    bool stop;

    i = 0;
    j = 0;
    stop = false;
    tmp_x = unit.getX();
    tmp_y = unit.getY();
    while (i < n)
    {
        if (direction == North)
            tmp_y -= 1;
        else if (direction == South)
            tmp_y += 1;
        else if (direction == East)
            tmp_x -= 1;
        else if (direction == West)
            tmp_x += 1;
        while (j < _units.size())
        {
            if (_units[j]->getOwner().getName() != unit.getOwner().getName() && _units[j]->getField() == unit.getField()
                && _units[j]->getX() == tmp_x && _units[j]->getY() == tmp_y && !stop) /*Monster in way*/
            {
                std::cout << "message: invalid move: enemy in the way" << std::endl;
                stop = true;
            }
            else if (!_map.canGo(tmp_x, tmp_y, unit) && !stop)
            {
                std::cout << "invalid move: no path" << std::endl;
                stop = true;
            }
            j++;
        }
        i++;
    }
    if (unit.getMp() < n && !stop)
        std::cout << "invalid move: mp" << std::endl;
    else if ((tmp_x < 0 || tmp_y < 0) && !stop)
        std::cout << "invalid move: oob" << std::endl;
    else if (canPlaceUnit(tmp_x, tmp_y, unit) && !stop)
        std::cout << "invalid move: cell occupied" << std::endl;
    else if (!stop)
    {
        unit.setMp(unit.getMp() - n);
        unit.setX(tmp_x);
        unit.setY(tmp_y);
    }
}

std::vector<Unit*> Game::getInRange(int x, int y, int rangeMin, int rangeMax, UnitField field)
{
    int i;
    std::vector<Unit*> inRange;

    i = 0;
    while (i < _units.size())
    {
        if (rangeMin < 0 || rangeMax < 0 || rangeMax < rangeMin)
            std::cout << "invalid range" << std::endl;
        else if (((_units[i]->getX() >= x + rangeMin && _units[i]->getX() <= x + rangeMax) // x en bas
                    || (_units[i]->getX() <= x - rangeMin && _units[i]->getX() >= x - rangeMax))  // x en haut
                 && ((_units[i]->getY() >= y + rangeMin && _units[i]->getY() <= y + rangeMax) // y en bas
                    || (_units[i]->getY() <= y - rangeMin && _units[i]->getY() >= y - rangeMax))  // y en haut
                 && _units[i]->getField() == field) // field
            inRange.push_back(_units[i]);
        i++;
    }
    return (inRange);
}
