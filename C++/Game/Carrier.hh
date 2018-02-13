#include "UnitField.hh"
#include "Unit.hh"
#include "Stats.hh"

class Carrier : public Unit
{
public:
    UnitField getField() const override;
    int getCost() const override;
    static Stats const& getBaseStats();
    void resetStats() override;
    void resetActions() override;
};
