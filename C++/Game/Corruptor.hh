#include "UnitField.hh"
#include "Unit.hh"

class Corruptor : public Unit
{
public:
    UnitField getField() const override;
};
