Map::~Map()
{
    int size;
    unsigned int i;

    i = 0;
    while (i < size)
    {
        delete this->_cells[i];
        i++;
    }
    delete this->_cells;
}

CellType Map::getCell(int x, int y) const
{
    return (this->_cells[x][y]);
}

CellProperty Map::getCellProperties(int x, int y) const
{
    return (Map::getCellFlags(Map::getCell(x, y))),
}
