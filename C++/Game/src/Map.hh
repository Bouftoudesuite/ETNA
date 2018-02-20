#ifndef _MAP_HH_
# define _MAP_HH_

#include "CellType.hh"
#include "CellProperty.hh"
#include "Unit.hh"

class Map
{
public:
    Map();
    int getWidth() const;
    int getHeight() const;
    CellType getCell(int x, int y) const;
    CellProperty getCellProperties(int x, int y);
    bool canGo(int x, int y, Unit const&);
    static int getDistanceBetween(int firstX, int firstY, int secondX, int secondY);
    ~Map();
private:
    int _width;
    int _height;
    CellType **_cells;
};

CellType** parseMap(int* width, int* height);

#endif