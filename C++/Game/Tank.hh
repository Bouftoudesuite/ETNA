#include "Unit.hh"

class Tank : public Unit
{
public:
    UnitField getField() const override;
    int getCost() const override;
};
