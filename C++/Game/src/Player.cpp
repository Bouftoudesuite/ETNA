#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Player.hh"

Player::Player(std::string const& name, unsigned int budget) : _name(name), _budget(budget)
{}

Player::~Player()
{}

unsigned int Player::getBudget() const
{
    return (_budget);
}

const std::string& Player::getName() const
{
    return (_name);
}

void Player::setBudget(unsigned int budget)
{
    _budget = budget;
}