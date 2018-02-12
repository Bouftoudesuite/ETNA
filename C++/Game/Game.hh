#include <vector>
#include "Map.hh"
#include "Unit.hh"

class Game
{
public:
    bool canPlaceUnit(int x, int y, Unit const& unit);
    bool placeUnit(Unit* unit);
    bool addUnit(Unit* unit);
private:
    Map _map;
    std::vector<Unit*> _units;
};
