#include <stdarg.h>

int my_strlen(const char * restrict str);
int my_str_ptr(int compteur, char lettre, va_list variables);
void my_putchar(char c);

int my_str_print(const char * restrict str, int* positions, char* lettres, va_list variables)
{
    int i;
    int j;
    int compteur;

    i = 0;
    j = 0;
    compteur = 0;
    while (str[i] != '\0')
    {
        if (i == positions[j])
        {
            compteur = my_str_ptr(compteur, lettres[j], variables);
            i++;
            j++;
        }
        else
        {
            my_putchar(str[i]);
            compteur++;
        }
        i++;
    }
    return compteur;
}