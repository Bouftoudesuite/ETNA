#include <stdlib.h>

int my_strlen(char* str);

// Renvoie les positions de toutes les lettres après pourcent
int* my_pos_pourcent(char* str)
{
    int size = my_strlen(str);
    int* positions = NULL;
    positions = malloc(sizeof(int) * size);
    int i = 0;
    int j = 0;

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
