#include "Unit.hh"

class Stalker : public Unit
{
public:
    UnitField getField() const override;
};
