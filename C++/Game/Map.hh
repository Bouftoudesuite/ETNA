#ifndef _MAP_H_
# define _MAP_H_

#include "CellType.hh"
#include "CellProperty.hh"

class Map
{
public:
    Map(const Map& M);             // constructeur par copie
    Map(Map && M);              // constructeur par déplacement
    Map& operator=(const Map& A);  // operateur d'affectation par copie
    Map& operator=(Map && M);        // opérateur d'affectation par déplacement
    ~Map();
    CellType getCell(const int x, const int y) const;
    CellProperty getCellProperties(const int x, const int y) const;
private:
    int _width;
    int _height;
    CellType **_cells;
};

Map& A::operator=(Map &&);
#endif
