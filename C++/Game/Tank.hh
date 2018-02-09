#include "Unit.hh"

class Tank : public Unit
{
public:
    UnitField getField() const override;
};
