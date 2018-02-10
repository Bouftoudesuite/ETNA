#ifndef _MAP_H_
# define _MAP_H_

#include "CellType.hh"
#include "CellProperty.hh"
#include "Unit.hh"

class Map
{
public:
    Map(int *width, int *height);
    Map(const Map& M) noexcept ;
    Map(Map && M) noexcept ;
    Map& operator=(const Map& A);
    Map& operator=(Map && M) noexcept ;
    CellType getCell(int x, int y) const;
    CellProperty getCellProperties(int x, int y);
    bool canGo(int x, int y, Unit const&);
    ~Map();
private:
    int _width;
    int _height;
    CellType **_cells;
};

#endif
