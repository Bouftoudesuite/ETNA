#include <stdlib.h>

int my_strlen(const char * restrict str);

int* my_pos_pourcent(const char * restrict str)
{
    int size;
    int* positions = NULL;
    int i;
    int j;

    i = 0;
    j = 0;
    size = my_strlen(str);
    positions = malloc(sizeof(int) * size);
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            positions[j] = i;
            j++;
        }
        positions[j] = -1;
        i++;
    }
    return positions;
}
