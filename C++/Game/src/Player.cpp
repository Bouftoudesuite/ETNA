#include "Player.hh"

Player::Player(std::string const& name, int budget) : _name(name), _budget(budget)
{}

int Player::getBudget() const
{
    return (_budget);
}

const std::string& Player::getName() const
{
    return (_name);
}

void Player::setBudget(int budget)
{
    _budget = budget;
}