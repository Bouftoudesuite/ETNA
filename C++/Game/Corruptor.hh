#include "UnitField.hh"
#include "Unit.hh"

class Corruptor : public Unit
{
public:
    virtual UnitField getField() const;
};
