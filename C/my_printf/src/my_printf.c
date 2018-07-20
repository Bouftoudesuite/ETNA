/*
** my_printf.c for my_ls in /Users/habi_a/Documents
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Jul 19 09:52:11 2018 HABI Açal
** Last update Thu Jul 19 10:03:46 2018 HABI Açal
*/

#include <flags.h>
#include <my.h>
#include <my_puts.h>
#include <pourcents.h>

static const t_flags g_flags[] =
{
    {'%', &my_put_no_flag},
    {'c', &my_put_c},
    {'s', &my_put_s},
    {'d', &my_put_d},
    {'i', &my_put_i},
    {'o', &my_put_o},
    {'u', &my_put_u},
    {'x', &my_put_x},
    {'X', &my_put_X}
};

static t_flags		get_flag(char key)
{
    unsigned int	i;
    t_flags		flag_error;

    i = 0;
    while (i < NB_FLAGS)
    {
        if (key == g_flags[i]._key)
            return (g_flags[i]);
        i++;
    }
    flag_error._key = '\0';
    flag_error.p_my_put = &my_put_error;
    return (flag_error);
}

static unsigned int	run(const char *str, t_list_pourcents *list_pourcents,
			    va_list variables)
{
    unsigned int	i;
    unsigned int	count;
    t_node_pourcents	*current_pourcent;

    i = 0;
    count = 0;
    current_pourcent = list_pourcents->_first;
    while (str[i] != '\0')
    {
        if (current_pourcent && i == current_pourcent->_position)
        {
            count = get_flag(current_pourcent->_letter)
	      .p_my_put(variables, count);
            current_pourcent = current_pourcent->_next;
            i++;
        }
        else
        {
            my_putchar(str[i]);
            count++;
        }
        i++;
    }
    return (count);
}

int			my_printf(const char *format, ...)
{
    unsigned int	ret_print;
    va_list		variables;
    t_list_pourcents	pourcents;

    va_start(variables, format);
    init_list_pourcents(&pourcents);
    fill_pourcents(&pourcents, format);
    ret_print = run(format, &pourcents, variables);
    free_list_pourcents(&pourcents);
    va_end(variables);
    return (ret_print);
}
