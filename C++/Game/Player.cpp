#include "Player.hh"

Player::Player(std::string const& name, int budget) : _name(name), _budget(budget)
{}

int Player::getBudget() const
{
    return (_budget);
}

void Player::setBudget(int budget)
{
    _budget = budget;
}