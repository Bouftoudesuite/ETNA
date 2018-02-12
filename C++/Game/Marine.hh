#include "UnitField.hh"
#include "Unit.hh"

class Marine : public Unit
{
public:
    UnitField getField() const override;
    int getCost() const override;
};
