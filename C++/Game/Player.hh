#ifndef _PLAYER_HH_
#define _PLAYER_HH_

#include <string>

class Player
{
public:
    Player(std::string const& name, int budget);
    int getBudget() const;
    void setBudget(int budget);
private:
    std::string _name;
    int _budget;
};

#endif
