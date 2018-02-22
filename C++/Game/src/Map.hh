#ifndef _MAP_HH_
# define _MAP_HH_

#include "CellType.hh"
#include "CellProperty.hh"
#include "Unit.hh"

class Map
{
public:
    Map();
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    CellType getCell(unsigned int x, unsigned int y) const;
    CellProperty getCellProperties(unsigned int x, unsigned int y);
    bool canGo(unsigned int x, unsigned int y, Unit const&);
    static unsigned int getDistanceBetween(unsigned int firstX, unsigned int firstY, unsigned int secondX, unsigned int secondY);
    ~Map();
private:
    unsigned int _width;
    unsigned int _height;
    CellType **_cells;
};

CellType** parseMap(unsigned int* width, unsigned int* height);

#endif
