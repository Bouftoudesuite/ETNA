#include <string>

class Castle
{
public:
    Castle(const std::string& name);
    int GetNbTowers() const;
    const std::string& GetName() const;
    void SetNbTowers(const int nbTowers);
    void CloseGates();
    void CloseGates(int nbDoors);
private:
    int _nbTowers;
    const std::string _name;
}

bool operator==(Castle const& a, Castle const& b);
bool operator!=(Castle const& a, Castle const& b);
bool operator>(Castle const& a, Castle const& b);
bool operator<(Castle const& a, Castle const& b);
bool operator>=(Castle const& a, Castle const& b);
bool operator<=(Castle const& a, Castle const& b);
