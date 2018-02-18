#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include "CellProperty.hh"
#include "Map.hh"

Map::Map(int width, int height) :
    _width(width),
    _height(height),
    _cells(parseMap(&_width, &_height))
{}

Map::~Map()
{
    unsigned int i;

    i = 0;
    while (i < _width)
    {
        delete[] _cells[_width];
        i++;
    }
    delete[] _cells;
}

CellType Map::getCell(const int x, const int y) const
{

    if (x < 0 || y < 0)
    {
        std::cout << "invalid cell coordinates" << std::endl;
    }
    return (_cells[x][y]);
}

CellProperty Map::getCellProperties(const int x, const int y)
{
    int i;
    CellProperty cell;

    i = getCellFlags(Map::getCell(x, y));
    if (i == FLYABLE)
    {
        cell.CellProperty::setFlyable();
    }
    else if (i == WALKABLE)
    {
        cell.setWalkable();
    }
    else if (i == SWIMMABLE)
    {
        cell.setSwimmable();
    }
    else if (i == (FLYABLE | WALKABLE))
    {
        cell.setFlyable();
        cell.setWalkable();
    }
    else if (i == (SWIMMABLE | FLYABLE))
    {
        cell.setSwimmable();
        cell.setFlyable();
    }
    else if (i == (SWIMMABLE | WALKABLE))
    {
        cell.setSwimmable();
        cell.setWalkable();
    }
    else if (i == (SWIMMABLE | WALKABLE | FLYABLE))
    {
        cell.setSwimmable();
        cell.setWalkable();
        cell.setFlyable();
    }
    return (cell);
}

bool Map::canGo(int x, int y, const Unit& unit)
{
    UnitField field;
    CellProperty property;

    property = this->getCellProperties(x, y);
    field = unit.getField();
    if (field == Sky && property.isFlyable())
    {
        return (true);
    }
    else if (field == Ground && property.isWalkable())
    {
        return (true);
    }
    else if (field == Water && property.isFlyable())
    {
        return (true);
    }
    return (false);
}

CellType** parseMap(int* width, int* height)
{
    char tmp;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    CellType** _cells;

    std::ifstream file("map.txt", std::ios::in);
    if(file)
    {
        i = 0;
        k = 0;
        _cells = new CellType*[*width];
        while (i < *width)
        {
            _cells[i] = new CellType[*height];
            i++;
        }
        j = 0;
        while (j < *height)
        {
            i = 0;
            while (i < *width)
            {
                file.get(tmp);
                if (tmp == 'G')
                    _cells[i][j] = GrassCell;
                else if (tmp == 'W')
                    _cells[i][j] = WaterCell;
                else if (tmp == 'R')
                    _cells[i][j] = RockCell;
                else if (tmp == 'M')
                    _cells[i][j] = MountainCell;
                else
                {
                    while (k < i)
                    {
                        delete[] _cells[k];
                        k++;
                    }
                    delete[] _cells;
                    std::cerr << "invalid map data" << std::endl;
                    return (nullptr);
                }
                i++;
            }
            j++;
        }
        file.close();
        return (_cells);
    }
    else
    {
        std::cout << "Cannot open file !" << std::endl;
        return (nullptr);
    }
}

int Map::getDistanceBetween(int firstX, int firstY, int secondX, int secondY)
{
    int distance;

    distance = std::abs(firstX - firstY) + std::abs(secondX - secondY);
    return (distance);
}
