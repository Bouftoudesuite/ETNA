#include <stdlib.h>

void my_putstr(const char * restrict str);
int my_strlen(const char * restrict str);

char* my_check_pourcent(const char * restrict str, int* positions)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(str) + 1;
    char* lettres = NULL;
    lettres = malloc(sizeof(char) * size);
    int tmp_pos = 0;

    while (positions[i] != -1)
    {
        tmp_pos = positions[i] + 1;
        if (str[tmp_pos] != 'e')
        {
            lettres[j] = str[tmp_pos];
            j++;
        }
        else
        {
            my_putstr("revoir usage");
            return NULL;
        }
        i++;
    }
    lettres[j] = '\0';
    return lettres;
}
