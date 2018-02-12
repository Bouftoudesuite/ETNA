#include "Unit.hh"

class Roach : public Unit
{
public:
    UnitField getField() const override;
    int getCost() const override;
};
