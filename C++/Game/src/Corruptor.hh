#ifndef _CORRUPTOR_HH_
# define _CORRUPTOR_HH_

#include "UnitField.hh"
#include "Unit.hh"
#include "Stats.hh"

class Corruptor : public Unit
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

#endif
