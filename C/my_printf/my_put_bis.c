/*
** my_put_bis.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:22:11 2017 HABI Açal
** Last update Thu Jan  4 21:06:30 2018 HABI Açal
*/
#include "my_printf.h"

int	my_put_o(va_list variables, int count, int arg_select)
{
    int	i;
    int	var;
    int	size;

    i = 0;
    var = 0;
    while (i <= arg_select)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr_base(var, "01234567");
    size = my_nbrlen(var);
    count += size;
    return (count);
}

int	my_put_u(va_list variables, int count, int arg_select)
{
    int	i;
    int	var;
    int	size;

    i = 0;
    var = 0;
    while (i <= arg_select)
    {
        var = va_arg(variables, unsigned int);
        i++;
    }
    my_put_un_nbr(var);
    size = my_nbrlen(var);
    count += size;
    return (count);
}

int	my_put_x(va_list variables, int count, int arg_select)
{
    int	i;
    int	var;
    int	size;

    i = 0;
    var = 0;
    while (i <= arg_select)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr_base(var, "0123456789ABCDEF");
    size = my_nbrlen(var);
    count += size;
    return (count);
}

int	my_put_X(va_list variables, int count, int arg_select)
{
    int	i;
    int	var;
    int	size;

    i = 0;
    var = 0;
    while (i <= arg_select)
    {
      var = va_arg(variables, int);
      i++;
    }
    my_put_nbr_base(var, "0123456789ABCDEF");
    size = my_nbrlen(var);
    count += size;
    return (count);
}

int my_put_error(va_list variables, int count, int arg_select)
{
    arg_select += va_arg(variables, int);
    count += arg_select - arg_select + 0;
    return (count);
}