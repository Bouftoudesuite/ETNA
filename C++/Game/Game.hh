#include <vector>
#include "Map.hh"
#include "Unit.hh"

class Game
{
public:
    bool canPlaceUnit(int x, int y, Unit const& unit);
    bool placeUnit(Unit* unit);
    bool addUnit(Unit* unit);
    void resetUnits();
    void newTurn();
private:
    Map _map;
    std::vector<Unit*> _units;
};

bool my_predicate(const Unit& item);