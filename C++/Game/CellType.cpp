#include <iostream>
#include <exception>
#include "Map.hh"

CellType** parseMap(int* width, int* height)
{
    char tmp;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    CellType** _cells;

    i = 0;
    k = 0;
    _cells = new CellType*[*width];
    while (i < *width)
    {
        _cells[i] = new CellType[*height];
        i++;
    }
    j = 0;
    while (j < *height)
    {
        i = 0;
        while (i < *width)
        {
            std::cin >> tmp;
            try
            {
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
                    throw std::runtime_error("invalid map data");
                }
            }
            catch (std::runtime_error &error)
            {
                std::cout << error.what() << std::endl;
            }
            i++;
        }
        j++;
    }
    return (_cells);
}
