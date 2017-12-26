/*
** my_put_bis.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:22:11 2017 HABI Açal
** Last update Tue Dec 26 13:47:19 2017 HABI Açal
*/
#include <stdarg.h>
#include "my_printf.h"

int		my_put_o(va_list variables, int compteur, int j)
{
    int		i;
    int		var;
    int		size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr_base(var, "01234567");
    size = my_nbrlen(var);
    compteur += size;
    return (compteur);
}

int		my_put_u(va_list variables, int compteur, int j)
{
    int		i;
    int		var;
    int		size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, unsigned int);
        i++;
    }
    my_put_un_nbr(var);
    size = my_nbrlen(var);
    compteur += size;
    return (compteur);
}

int		my_put_x(va_list variables, int compteur, int j)
{
    int		i;
    int		var;
    int		size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr_base(var, "0123456789ABCDEF");
    size = my_nbrlen(var);
    compteur += size;
    return (compteur);
}

int		my_put_X(va_list variables, int compteur, int j)
{
    int		i;
    int		var;
    int		size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr_base(var, "0123456789ABCDEF");
    size = my_nbrlen(var);
    compteur += size;
    return (compteur);
}
