#include <iostream>
#include <string>
#include "Map.hh"
#include "CellType.hh"

CellType** parseMap()
{
    char tmp;
    unsigned int i;
    unsigned int j;
    unsigned column;
    unsigned row;
    CellType** _cells;

    i = 0;
    std::cin >> column;
    std::cin >> row;
    _cells = new CellType*[column];
    while (i < column)
    {
        _cells[i] = new CellType[row];
        i++;
    }
    j = 0;
    while (j < row)
    {
        i = 0;
        while (i < column)
        {
            std::cin >> tmp;
            if (tmp == 'G')
              _cells[i][j] = G;
            else if (tmp == 'W')
              _cells[i][j] = W;
            else if (tmp == 'R')
                _cells[i][j] = R;
            else if (tmp == 'M')
                _cells[i][j] = M;
            i++;
        }
        j++;
    }
    return _cells;
}
