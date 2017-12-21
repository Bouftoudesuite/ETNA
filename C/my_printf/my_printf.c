#include <stdlib.h>
#include <stdarg.h>

char* my_check_pourcent(char* str, int* positions);
int* my_pos_pourcent(char* str);
char* my_str_print(char* str, int* positions, char* lettres, va_list variables);
void my_putstr(char* str);
int my_strlen(char* str);
void my_put_nbr(int n);
void my_putchar(char c);

void my_printf(char* str, ...)
{
    va_list variables;

    int* positions = my_pos_pourcent(str);
    char* lettres = my_check_pourcent(str, positions);
    int nb_args = my_strlen(lettres);

    va_start(variables, nb_args);
    my_str_print(str, positions, lettres, variables);
    free(lettres);
    free(positions);
}
