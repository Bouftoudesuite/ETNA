#include <stdlib.h>
#include <stdarg.h>

char* my_check_pourcent(const char * restrict str, int* positions);
int* my_pos_pourcent(const char * restrict str);
int my_str_print(const char * restrict str, int* positions, char* lettres, va_list variables);
void my_putstr(const char * restrict str);
int my_strlen(const char * restrict str);
void my_put_nbr(int n);
void my_putchar(char c);

int my_printf(const char * restrict str, ...)
{
    va_list variables;
    va_start(variables, str);
    int* positions = my_pos_pourcent(str);
    char* lettres = my_check_pourcent(str, positions);
    int return_print;
    return_print = my_str_print(str, positions, lettres, variables);
    free(lettres);
    free(positions);
    va_end(variables);
    return return_print;
}
