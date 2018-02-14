#ifndef _UNIT_HH_
# define _UNIT_HH_

#include "UnitField.hh"
#include "Player.hh"
#include "Stats.hh"

class Unit
{
public:
    Unit(int x, int y, Player& player);
    bool isDead() const;
    int getX() const;
    int getY() const;
    int getHp() const;
    int getPp() const;
    int getAp() const;
    int getMp() const;
    Player& getOwner();
    virtual UnitField getField() const = 0;
    virtual int getCost() const = 0;
    virtual int getAttackRange() const = 0;
    virtual int getAttackMinRange() const = 0;
    virtual int getAttackArea() const = 0;
    void setX(int x);
    void setY(int y);
    void setHp(int hp);
    void setPp(int pp);
    void setAp(int ap);
    void setMp(int mp);
    virtual void resetStats() = 0;
    virtual void resetActions() = 0;
private:
    int _x;
    int _y;
    Player& _player;
    Stats _stats;
};

#endif