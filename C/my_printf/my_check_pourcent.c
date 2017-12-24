#include <stdlib.h>

void my_putstr(const char * restrict str);
int my_strlen(const char * restrict str);

char* my_check_pourcent(const char * restrict str, int* positions)
{
    int i = 0;
    int j = 0;
    int size;
    char* lettres = NULL;
    int tmp_pos;

    i = 0;
    j = 0;
    size = my_strlen(str) + 1;
    lettres = malloc(sizeof(char) * size);
    while (positions[i] != -1)
    {
        tmp_pos = positions[i] + 1;
        lettres[j] = str[tmp_pos];
        j++;
        i++;
    }
    lettres[j] = '\0';
    return lettres;
}
