#ifndef _ATTACK_HH_
#define _ATTACK_HH_

#include "Game.hh"
#include "Unit.hh"

class Attack
{
public:
    Attack(Game const& game, Unit& unit);
private:
    Game _game;
    Unit& _unit;
};

#endif
