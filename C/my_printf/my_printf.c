#include <stdlib.h>
#include <stdarg.h>

char* my_check_pourcent(const char * restrict str, int* positions);
int* my_pos_pourcent(const char * restrict str);
int my_str_print(const char * restrict str, int* positions, char* lettres, va_list variables);

int my_printf(const char * restrict str, ...)
{
    int* positions;
    char* lettres;
    int return_print;

    va_list variables;
    va_start(variables, str);
    positions = my_pos_pourcent(str);
    lettres = my_check_pourcent(str, positions);
    return_print = my_str_print(str, positions, lettres, variables);
    free(lettres);
    free(positions);
    va_end(variables);
    return return_print;
}
