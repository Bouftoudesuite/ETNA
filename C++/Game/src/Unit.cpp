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

int Unit::getHpMax() const
{
    return (_stats._hpMax);
}

int Unit::getPpMax() const
{
    return (_stats._ppMax);
}

int Unit::getApMax() const
{
    return (_stats._apMax);
}

int Unit::getMpMax() const
{
    return (_stats._mpMax);
}

Player& Unit::getOwner()
{
    return (_player);
}

void Unit::setX(int x)
{
    _x = x;
}

void Unit::setY(int y)
{
    _y = y;
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

void Unit::setHpMax(int hp)
{
    _stats._hpMax = hp;
}

void Unit::setPpMax(int pp)
{
    _stats._ppMax = pp;
}

void Unit::setApMax(int ap)
{
    _stats._apMax = ap;
}

void Unit::setMpMax(int mp)
{
    _stats._mpMax = mp;
}