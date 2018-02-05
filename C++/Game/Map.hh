#include "CellType.hh"
#include "CellProperty.hh"

class Map
{
public:
    ~Map();
    CellType getCell(int x, int y) const;
    CellProperty getCellProperties(int x, int y) const;
private:
    CellType **_cells;
};
