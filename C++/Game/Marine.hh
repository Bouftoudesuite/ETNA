#include "UnitField.hh"
#include "Unit.hh"

class Marine : public Unit
{
public:
    virtual UnitField getField() const;
};
