#include "Unit.hh"

class Ursadon : public Unit
{
public:
    UnitField getField() const override;
    int getCost() const override;
};
