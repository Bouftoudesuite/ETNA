#include "map.hh"
#include "CellType.hh"
#include "CellProperty.hh"

Map::Map(const int width, const int height) :
    _width(6),
    _height(5),
    _cells(parseMap(_width, _height))
{}

Map::Map(const Map& M) : _width(M._width), _height(M._height), _cells(M._cells)
{}

Map::Map(Map && M) : _width(M._width), _height(M._height), _cells(M._cells)
{
    unsigned int i;

    i = 0;
    while (i < _width)
    {
        delete[] _cells[_width];
        i++;
    }
    delete[] _cells;
    M._width = 0;
    M._height = 0;
    M._cells = NULL;
}

Map& Map::operator=(const Map& M)
{
    if (this != M)
    {
        unsigned int i;

        i = 0;
        while (i < _width)
        {
            delete[] _cells[_width];
            i++;
        }
        delete[] _cells;
        _width = M._width;
        _height = M._height;
        _cells = M._cells;
    }
    return (*this);
}

Map& Mapp::operator=(Map && M)
{
    if (this != M)
    {
        unsigned int i;

        i = 0;
        while (i < _width)
        {
            delete[] _cells[_width];
            i++;
        }
        delete[] _cells;
        _width = M._width;
        _height = M._height;
        _cells = M._cells;
        i = 0;
        while (i < _width)
        {
            delete[] _cells[_width];
            i++;
        }
        delete[] _cells;
        M._width = 0;
        M._height = 0;
        M._cells = NULL;
    }
    return (*this);
}

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
    return (_cells[x][y]);
}

CellProperty Map::getCellProperties(const int x, const int y) const
{
    int i;
    CellProperty cell();

    i = getCellFlags(this.getCell(x, y));
    if (i == FLYABLE)
        cell._flyable = true;
    else if (i == WALKABLE)
        cell._walkable = true;
    else if (i == SWIMMABLE)
        cell._swimmable = true;
    else if (i == (FLYABLE | WALKABLE)
    {
        cell._flyable = true;
        cell._walkable = true;
    }
    else if (i == (SWIMMABLE | FLYABLE))
    {
        cell._swimmable = true;
        cell._flyable = true;
    }
    else if (i == (SWIMMABLE | WALKABLE))
    {
        cell._swimmable = true;
        cell._walkable = true;
    }
    else if (i == (SWIMMABLE | WALKABLE | FLYABLE))
    {
        cell._swimmable = true;
        cell._walkable = true;
        cell._flyable = true;
    }
    return (cell);
}

bool Map::canGo(int x, int y, const Unit& unit)
{
    UnitField field;

    field = unit.getField();
    return;
}
