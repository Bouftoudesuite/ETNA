#include "Roach.hh"

UnitField Roach::getField() const
{
    return (Ground);
}

int Roach::getCost() const
{
    return (150);
}

int Roach::getAttackRange() const
{
    return (2);
}

int Roach::getAttackMinRange() const
{
    return (1);
}

int Roach::getAttackArea() const
{
    return (1);
}

Stats const& Roach::getBaseStats()
{
    static Stats stats {200, 5, 6, 3};
    return (stats);
}

void Roach::resetStats()
{
    Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setHp(stats._hp);
    setPp(stats._pp);
    setAp(stats._ap);
    setMp(stats._mp);
}

void Roach::resetActions()
{
    static Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setAp(stats._ap);
    setMp(stats._mp);
}