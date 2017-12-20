#include <stdlib.h>

void my_putstr(char* str);
int my_strlen(char* str);

char* my_check_pourcent(char* str, int* positions)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(str) + 1;
    char variables[size];
    int tmp_pos = 0;

    while (positions[i] != -1)
    {
        tmp_pos = positions[i] + 1;
        if (str[tmp_pos] != 'e')
        {
            variables[j] = str[tmp_pos];
            j++;
        }
        else
        {
            my_putstr("revoir usage");
            return NULL;
        }
        i++;
    }
    return variables;
}
