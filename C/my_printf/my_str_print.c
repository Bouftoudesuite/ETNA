#include <stdarg.h>

int my_strlen(char* str);
void my_putchar(char c);
void my_putstr(char* str);
void my_put_nbr(int n);

void my_str_print(char* str, int* positions, char* lettres, va_list variables)
{
    int nb_args = my_strlen(lettres);
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0')
    {
        if (i == positions[k])
        {
            if (lettres[k] == 'c')
                my_putchar(va_arg(variables, char));
            else if (lettres[k] == 'd')
                my_put_nbr(va_arg(variables, int));
            i++;
            j++;
            k++;
        }
        else
        {
            my_putchar(str[i]);
            j++;
        }
        i++;
    }
    va_end(variables);
}