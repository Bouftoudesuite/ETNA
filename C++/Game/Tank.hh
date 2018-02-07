#include "Unit.hh"

class Tank : public Unit
{
public:
    virtual UnitField getField() const;
};
