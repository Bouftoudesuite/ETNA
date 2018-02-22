#ifndef _PLAYER_HH_
# define _PLAYER_HH_

#include <SFML/Graphics.hpp>
#include <string>

class Player
{
public:
    Player(std::string const& name, unsigned int budget);
    ~Player();
	unsigned int getBudget() const;
    const std::string& getName() const;
    void setBudget(unsigned int budget);
private:
    std::string _name;
	unsigned int _budget;
};

#endif
