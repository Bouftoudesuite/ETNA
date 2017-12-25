#include "my_ptr_func.h"

void        my_putchar(char c);
int         my_convert_letter_into_nb(char lettre);

int         my_str_print(const char *str, int *positions, char *lettres,
                            va_list variables)
{
    int     i;
    int     j;
    int     compteur;

    i = 0;
    j = 0;
    compteur = 0;
    while (str[i] != '\0')
    {
        if (i == positions[j])
        {
            compteur = ptr_func[my_convert_letter_into_nb(lettres[j])]
                    (variables, compteur, j);
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
    return (compteur);
}