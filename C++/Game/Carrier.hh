#include "UnitField.hh"
#include "Unit.hh"

class Carrier : public Unit
{
public:
    UnitField getField() const override;
    int getCost() const override;

};
