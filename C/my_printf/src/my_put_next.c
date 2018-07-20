/*
** my_put_next.c for my_ls in /Users/habi_a/Documents
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Jul 19 10:09:54 2018 HABI Açal
** Last update Thu Jul 19 11:45:51 2018 HABI Açal
*/

#include <my.h>
#include <my_puts.h>

unsigned int		my_put_o(va_list variables, unsigned int count)
{
    unsigned int	var;

    var = va_arg(variables, unsigned int);
    my_put_un_nbr_base(var, "01234567");
    count += my_nbrlen(var);
    return (count);
}

unsigned int		my_put_u(va_list variables, unsigned int count)
{
    unsigned int	var;

    var = va_arg(variables, unsigned int);
    my_put_un_nbr(var);
    count += my_nbrlen(var);
    return (count);
}

unsigned int		my_put_x(va_list variables, unsigned int count)
{
    unsigned int	var;

    var = va_arg(variables, unsigned int);
    my_put_un_nbr_base(var, "0123456789abcdef");
    count += my_nbrlen(var);
    return (count);
}

unsigned int		my_put_X(va_list variables, unsigned int count)
{
    unsigned int	var;

    var = va_arg(variables, unsigned int);
    my_put_un_nbr_base(var, "0123456789ABCDEF");
    count += my_nbrlen(var);
    return (count);
}

unsigned int		my_put_error(va_list variables, unsigned int count)
{
    (void) variables;
    return (count);
}
