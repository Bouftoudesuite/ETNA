#include "Marine.hh"

UnitField Marine::getField() const
{
    return (Ground);
}

int Marine::getCost() const
{
    return (50);
}

Stats const& Marine::getBaseStats()
{
    static Stats stats {50, 5, 6, 3};
    return (stats);
}

void Marine::resetStats()
{
    Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setHp(stats._hp);
    setPp(stats._pp);
    setAp(stats._ap);
    setMp(stats._mp);
}

void Marine::resetActions()
{
    static Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setAp(stats._ap);
    setMp(stats._mp);
}