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
#include "my_printf.h"

int		my_str_print(const char *str, int *positions, char *letters,
			     va_list variables)
{
    int		i;
    int		j;
    int		count;
    int     arg_select;

    i = 0;
    j = 0;
    count = 0;
    arg_select = 0;
    while (str[i] != '\0')
    {
        if (i == positions[j])
        {
            count = ptr_func[my_convert_letter_into_nb(letters[j])]
                    (variables, count, arg_select);
            if (letters[j] != '%')
                arg_select++;
            i++;
            j++;
        }
        else
            count = my_str_print_help(str, i, count);
        i++;
    }
    return (count);
}

int my_str_print_help(const char *str, int i, int count)
{
    my_putchar(str[i]);
    count++;
    return (count);
}