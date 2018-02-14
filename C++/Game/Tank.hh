#include "Unit.hh"
#include "Stats.hh"

class Tank : public Unit
{
public:
    UnitField getField() const override;
    int getCost() const override;
    int getAttackRange() const override;
    int getAttackMinRange() const override;
    int getAttackArea() const override;
    static Stats const& getBaseStats();
    void resetStats() override;
    void resetActions() override;
};
