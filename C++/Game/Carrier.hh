#include "UnitField.hh"
#include "Unit.hh"

class Carrier : public Unit
{
public:
    virtual UnitField getField() const;
};
