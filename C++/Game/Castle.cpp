#include <iostream>
#include <string>
#include "Castle.hh"

bool operator==(Castle const& a, Castle const& b)
{
    return (a.GetName() == b.GetName() && a.GetNbTowers() == b.GetNbTowers());
}

bool operator!=(Castle const& a, Castle const& b)
{
    return (a.GetName() != b.GetName() || a.GetNbTowers() != b.GetNbTowers());
}

bool operator>(Castle const& a, Castle const& b)
{
    return (a.GetNbTowers() > b.GetNbTowers());
}

bool operator<(Castle const& a, Castle const& b)
{
    return (a.GetNbTowers() < b.GetNbTowers());
}

bool operator>=(Castle const& a, Castle const& b)
{
    return (a.GetNbTowers() >= b.GetNbTowers());
}

bool operator<=(Castle const& a, Castle const& b)
{
    return (a.GetNbTowers() <= b.GetNbTowers());
}

Castle::Castle(const std::string& name) : _nbTowers(0), _name(name)
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