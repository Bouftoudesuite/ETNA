/*
** my_put_next_bis.c for my_printf in /Users/habi_a/Documents
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Mon Jul 23 16:16:53 2018 HABI Açal
** Last update Mon Jul 23 16:37:43 2018 HABI Açal
*/

#include <my.h>
#include <my_puts.h>
#include <stdlib.h>

unsigned int            my_put_b(va_list variables, unsigned int count)
{
    unsigned int        var;
    unsigned int        *buffer_size;

    buffer_size = malloc(sizeof(unsigned int));
    *buffer_size = 0;
    var = va_arg(variables, unsigned int);
    my_put_un_nbr_base(var, "01");
    my_un_nbrlen_base(var, "01", buffer_size);
    count += *buffer_size;
    free(buffer_size);
    return (count);
}

unsigned int		my_put_error(va_list variables, unsigned int count)
{
    (void) variables;
    return (count);
}
