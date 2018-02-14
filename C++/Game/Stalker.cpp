#include "Stalker.hh"

UnitField Stalker::getField() const
{
    return (Ground);
}

int Stalker::getCost() const
{
    return (100);
}

int Stalker::getAttackRange() const
{
    return (3);
}

int Stalker::getAttackMinRange() const
{
    return (1);
}

int Stalker::getAttackArea() const
{
    return (1);
}

Stats const& Stalker::getBaseStats()
{
    static Stats stats {100, 10, 6, 3};
    return (stats);
}

void Stalker::resetStats()
{
    Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setHp(stats._hp);
    setPp(stats._pp);
    setAp(stats._ap);
    setMp(stats._mp);
}

void Stalker::resetActions()
{
    static Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setAp(stats._ap);
    setMp(stats._mp);
}