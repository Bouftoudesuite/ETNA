#include <stdarg.h>

int my_strlen(const char * restrict str);
void my_putchar(char c);
void my_putstr(const char * restrict str);
void my_put_nbr(int n);

int my_str_print(const char * restrict str, int* positions, char* lettres, va_list variables)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int compteur = 0;

    while (str[i] != '\0')
    {
        if (i == positions[k])
        {
            if (lettres[k] == 'c')
            {
                my_putchar(va_arg(variables, char));
                compteur++;
            }
            else if (lettres[k] == 'd')
            {
                my_put_nbr(va_arg(variables, int));
                compteur++;
            }
            i++;
            j++;
            k++;
        }
        else
        {
            my_putchar(str[i]);
            compteur++;
            j++;
        }
        i++;
    }
    va_end(variables);
    return compteur;
}