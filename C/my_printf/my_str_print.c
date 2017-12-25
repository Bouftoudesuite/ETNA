#include "my_ptr_func.h"

void my_putchar(char c);
int my_convert_letter_into_nb(char lettre);

int my_str_print(const char * restrict str, int* positions, char* lettres, va_list variables)
{
    int i;
    int j;
    int compteur;
    int nb_function;
    i = 0;
    j = 0;
    compteur = 0;
    while (str[i] != '\0')
    {
        if (i == positions[j])
        {
            nb_function = my_convert_letter_into_nb(lettres[j]);
            compteur = ptr_func[nb_function](variables, compteur, j);
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