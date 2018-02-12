#ifndef _UNIT_HH_
# define _UNIT_HH_

#include "UnitField.hh"
#include "Player.hh"
class Unit
{
public:
    Unit(int x, int y, Player& player);
    int getX() const;
    int getY() const;
    Player& getOwner();
    virtual UnitField getField() const = 0;
    virtual int getCost() const = 0;
private:
    int _x;
    int _y;
    Player& _player;
};

#endif