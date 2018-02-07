#include <iostream>
#include <string>
#include "Castle.hh"

bool operator==(Castle const& a, Castle const& b)
{
    if (a._name == b._name && a._nbTowers == b._nbTowers)
        return (true);
    else
        return (false);
}

bool operator!=(Castle const& a, Castle const& b)
{
    if (a._name != b._name || a._nbTowers != b._nbTowers)
        return (true);
    else
        return (false);
}

bool operator>(Castle const& a, Castle const& b)
{
    if (a._nbTowers > b._nbTowers)
        return (true);
    else
        return (false);
}

bool operator<(Castle const& a, Castle const& b)
{
    if (a._nbTowers < b._nbTowers)
        return (true);
    else
        return (false);
}

bool operator>=(Castle const& a, Castle const& b)
{
    if (a._nbTowers >= b._nbTowers)
        return (true);
    else
        return (false);
}

bool operator<=(Castle const& a, Castle const& b)
{
    if (a._nbTowers <= b._nbTowers)
        return (true);
    else
        return (false);
}

Castle(const std::string& name) : _nbTowers(0), _name(name)
{}

int Castle::GetNbTowers() const
{
    return (_nbTowers);
}

const std::string& Castle::GetName() const
{
    return (_name);
}

void Castle::SetNbTowers(const int nbTowers)
{
    _nbTowers = nbTowers;
}

void Castle::CloseGates()
{
    std::cout << "Close the gates!" << std::endl;
}

void Castle::CloseGates(int nbDoors)
{
    std::cout << "Close only " << nbDoors << " doors" << std::endl;
}
