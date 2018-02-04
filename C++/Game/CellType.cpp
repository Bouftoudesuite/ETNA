#include <iostream>
#include <string>
#include "Map.hh"
#include "CellType.hh"

CellType** parseMap()
{
    unsigned int i;
    unsigned int j;
    unsigned column;
    unsigned row;
    char** _cells;

    i = 0;
    std::cin >> column;
    std::cin >> row;
    _cells = new char*[column];
    while (i < column)
    {
        _cells[i] = new char[row];
        i++;
    }
    j = 0;
    while (j < column)
    {
        i = 0;
        while (i < row)
        {
            std::cin >> _cells[i][j];
            i++;
        }
        j++;
    }
    return (CellType**)_cells;
}
