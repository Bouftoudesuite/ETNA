#include "UnitField.hh"

class Unit
{
public:
    Unit(const int x, const int y);
    UnitField getField() const;
private:
    int _x;
    int _y;
}
