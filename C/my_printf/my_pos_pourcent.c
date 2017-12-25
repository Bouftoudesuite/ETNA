#include <stdlib.h>

int my_strlen(const char * restrict str);
int* my_pos_pourcent_bis(const char * restrict str, int* positions);

int* my_pos_pourcent(const char * restrict str)
{
    int size;
    int* positions;

    size = my_strlen(str);
    positions = malloc(sizeof(int) * (size + 1));
    if (positions == NULL)
        exit(0);
    positions = my_pos_pourcent_bis(str, positions);
    return positions;
}

int* my_pos_pourcent_bis(const char * restrict str, int* positions)
{
    int i;
    int j;

    i = 0;
    j = 0;
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