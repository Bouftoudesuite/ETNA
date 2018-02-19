#include <SFML/Graphics.hpp>
#include <vector>
#include "Cscreen.hh"
#include "Map.hh"
#include "Menu.hh"
#include "Unit.hh"
#include "Player.hh"
#include "Direction.hh"

class Game : public Cscreen
{
public:
    Game(float width, float height, int nbPlayer);
    ~Game();
    void setWidth(Map map);
    void setHeight(Map map);
    void setMap(Map map);
    bool canPlaceUnit(int x, int y, Unit const& unit);
    bool placeUnit(Unit* unit);
    bool addUnit(Unit* unit);
    void resetUnits();
    void newTurn();
    bool didLose(Player const& player);
    void moveUnit(Unit& unit, Direction direction, int n);
    std::vector<Unit*> getInRange(int x, int y, int rangeMin, int rangeMax, UnitField field);
    int Run(sf::RenderWindow &window) override;
private:
    int _nbPlayer;
    float _width;
    float _height;
    Map _map;
    std::vector<Player*> _player;
    std::vector<Unit*> _units;
};

bool my_predicate(const Unit& item);
