#include "Unit.hh"

Unit::Unit(const int x, const int y, Player& player) : _x(x), _y(y), _player(player)
{}

bool Unit::isDead() const
{
    return (getHp() <= 0);
}

int Unit::getX() const
{
    return (_x);
}

int Unit::getY() const
{
    return (_y);
}

int Unit::getHp() const
{
    return (_stats._hp);
}

int Unit::getPp() const
{
    return (_stats._pp);
}

int Unit::getAp() const
{
    return (_stats._ap);
}

int Unit::getMp() const
{
    return (_stats._mp);
}

Player& Unit::getOwner()
{
    return (_player);
}

void Unit::setHp(int hp)
{
    _stats._hp = hp;
}

void Unit::setPp(int pp)
{
    _stats._pp = pp;
}

void Unit::setAp(int ap)
{
    _stats._ap = ap;
}

void Unit::setMp(int mp)
{
    _stats._mp = mp;
}