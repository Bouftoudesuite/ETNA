#include "Corruptor.hh"

UnitField Corruptor::getField() const
{
    return (Sky);
}

int Corruptor::getCost() const
{
    return (200);
}

Stats const& Corruptor::getBaseStats()
{
    static Stats stats {150, 15, 6, 3};
    return (stats);
}

void Corruptor::resetStats()
{
    Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setHp(stats._hp);
    setPp(stats._pp);
    setAp(stats._ap);
    setMp(stats._mp);
}

void Corruptor::resetActions()
{
    static Stats stats {0 , 0, 0, 0};

    stats = getBaseStats();
    setAp(stats._ap);
    setMp(stats._mp);
}