#include "Ursadon.hh"

UnitField Ursadon::getField() const
{
    return (Water);
}

int Ursadon::getCost() const
{
    return (30);
}

Stats const& Ursadon::getBaseStats()
{
    static Stats stats {300, 2, 6, 3};
    return (stats);
}

void Ursadon::resetStats()
{
    Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setHp(stats._hp);
    setPp(stats._pp);
    setAp(stats._ap);
    setMp(stats._mp);
}

void Ursadon::resetActions()
{
    static Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setAp(stats._ap);
    setMp(stats._mp);
}