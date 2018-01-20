/*
** my_put.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:19:03 2017 HABI Açal
** Last update Tue Jan  9 21:51:04 2018 HABI Açal
*/
#include <stdarg.h>
#include "my_printf.h"

int		my_put_no_flag(va_list variables, int count, int arg_select)
{
    my_putchar('%');
    arg_select += va_arg(variables, int);
    count += arg_select - arg_select + 0;
    return (count);
}

int		my_put_c(va_list variables, int count, int arg_select)
{
    int		i;
    char	var;

    i = 0;
    var = '\0';
    while (i <= arg_select)
    {
        var = (char)va_arg(variables, int);
        i++;
    }
    my_putchar(var);
    count++;
    return (count);
}

int		my_put_d(va_list variables, int count, int arg_select)
{
    int		i;
    int		var;
    int		size;

    i = 0;
    var = 0;
    while (i <= arg_select)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr(var);
    size = my_nbrlen(var);
    count += size;
    return (count);
}

int		my_put_i(va_list variables, int count, int arg_select)
{
    int		i;
    int		var;
    int		size;

    i = 0;
    var = 0;
    while (i <= arg_select)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr(var);
    size = my_nbrlen(var);
    count += size;
    return (count);
}

int		my_put_s(va_list variables, int count, int arg_select)
{
    int		i;
    char	*var;
    int		size;

    i = 0;
    var = 0;
    while (i <= arg_select)
    {
        var = va_arg(variables, char*);
        i++;
    }
    my_putstr(var);
    size = my_strlen(var);
    count += size;
    return (count);
}
