#include "map.hh"
#include "CellType.hh"
#include "CellProperty.hh"

Map::Map() : _cells(parseMap())
{}

Map::~Map(column)
{
    unsigned int i;

    i = 0;
    while (i < column)
    {
        delete[] this->_cells[column];
        i++;
    }
    delete[] this->_cells;
}

CellType Map::getCell(int x, int y) const
{
    return (this->_cells[x][y]);
}

CellProperty Map::getCellProperties(int x, int y) const
{
    int i;
    CellProperty cell();

    i = Map::getCellFlags(Map::getCell(x, y));
    if (i == FLYABLE)
        cell->_flyable = true;
    else if (i == WALKABLE)
        cell->_walkable = true;
    else if (i == SWIMMABLE)
        cell->_swimmable = true;
    else if (i == (FLYABLE | WALKABLE)
    {
        cell->_flyable = true;
        cell->_walkable = true;
    }
    else if (i == (SWIMMABLE | FLYABLE))
    {
        cell->_swimmable = true;
        cell->_flyable = true;
    }
    else if (i == (SWIMMABLE | WALKABLE))
    {
        cell->_swimmable = true;
        cell->_walkable = true;
    }
    else if (i == (SWIMMABLE | WALKABLE | FLYABLE))
    {
        cell->_swimmable = true;
        cell->_walkable = true;
        cell->_flyable = true;
    }
    return (cell);
}
