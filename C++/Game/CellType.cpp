#include <iostream>
#include <string>
#include "Map.hh"
#include "CellType.hh"

CellType** parseMap()
{
    char tmp;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    unsigned int l;
    unsigned column;
    unsigned row;
    CellType** _cells;

    i = 0;
    k = 0;
    std::cin >> column;
    std::cin >> row;
    if (row <= 0 || column <= 0)
        return (NULL);
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
                _cells[i][j] = GrassCell;
            else if (tmp == 'W')
                _cells[i][j] = WaterCell;
            else if (tmp == 'R')
                _cells[i][j] = RockCell;
            else if (tmp == 'M')
                _cells[i][j] = MountainCell;
            else
            {
                while (k < i)
  	            {
                    delete[] _cells[k];
                    k++;
                }
                delete[] _cells;
                return (NULL);
            }
            i++;
        }
        j++;
    }
    return _cells;
}
