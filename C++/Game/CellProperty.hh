class CellProperty
{
public:
    CellProperty();
    CellProperty(CellType newCellType);
    bool isWalkable() const;
    bool isSwimmable() const;
    bool isFlyable() const;
    bool isEvent() const;
    bool isMonster() const;
    void setWalkable();
    void setNotWalkable();
    void setSwimmable();
    void setNotSwimmable();
    void setFlyable();
    void setNotFlyable();
    void setEvent();
    void setNotEvent();
    void setMonster();
    void setNotMonster();
private:
    bool _walkable;
    bool _swimmable;
    bool _flyable;
    bool _event;
    bool _monster;
};
