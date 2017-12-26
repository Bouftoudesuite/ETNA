/*
** my_str_print.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:20:41 2017 HABI Açal
** Last update Tue Dec 26 13:24:34 2017 HABI Açal
*/
#include "my_ptr_func.h"

void		my_putchar(char c);
int		my_convert_letter_into_nb(char lettre);

int		my_str_print(const char *str, int *positions, char *lettres,
			     va_list variables)
{
    int		i;
    int		j;
    int		compteur;

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
