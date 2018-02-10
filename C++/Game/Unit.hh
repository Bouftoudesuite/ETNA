#ifndef _UNIT_HH_
# define _UNIT_HH_

#include "UnitField.hh"

class Unit
{
public:
    Unit();
    Unit(int x, int y);
    int getX() const;
    int getY() const;
    virtual UnitField getField() const;
private:
    int _x;
    int _y;
};

#endif