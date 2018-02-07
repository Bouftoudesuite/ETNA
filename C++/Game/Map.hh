#ifndef _MAP_H_
# define _MAP_H_

#include "CellType.hh"
#include "CellProperty.hh"

class Map
{
public:
    Map(const Map& M);
    Map(Map && M);
    Map& operator=(const Map& A);
    Map& operator=(Map && M);
    ~Map();
    CellType getCell(const int x, const int y) const;
    CellProperty getCellProperties(const int x, const int y) const;
    bool canGo(int x, int y, Unit const&);
private:
    int _width;
    int _height;
    CellType **_cells;
};

Map& A::operator=(Map &&);
#endif
