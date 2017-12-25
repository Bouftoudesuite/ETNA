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
    positions = malloc(sizeof(int) * (size + 1));
    while (str[i] != '\0')
    {
        if (str[i] == '%' && str[i + 1] != '%')
        {
            positions[j] = i;
            j++;
        }
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            positions[j] = i;
            i++;
            j++;
        }
        i++;
    }
    positions[j] = -1;
    return positions;
}
