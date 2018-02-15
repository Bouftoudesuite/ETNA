#ifndef _ATTACK_HH_
#define _ATTACK_HH_

#include "Game.hh"
#include "Unit.hh"
#include "Tank.hh"

template<class T>
class Attack
{
public:
    Attack(Game const& game, Unit& unit);
    void perform(int x, int y);
private:
    Game _game;
    Unit& _unit;
};

template<class T>
class Attack<Tank>
{
public:
    Attack(Game const& game, Unit& unit);
    void perform(int x, int y);
private:
    Game _game;
    Unit& _unit;
};

#endif
