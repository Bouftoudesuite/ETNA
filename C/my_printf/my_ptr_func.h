/*
** my_ptr_func.h for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:21:22 2017 HABI Açal
** Last update Tue Dec 26 14:54:27 2017 HABI Açal
*/
#ifndef		_MY_PTR_FUNC_H_
#define		_MY_PTR_FUNC_H_

#include	<stdarg.h>

int		my_put_no_flag(va_list variables, int count, int arg_select);
int		my_put_c(va_list variables, int count, int arg_select);
int		my_put_i(va_list variables, int count, int arg_select);
int		my_put_d(va_list variables, int count, int arg_select);
int		my_put_s(va_list variables, int count, int arg_select);
int		my_put_o(va_list variables, int count, int arg_select);
int		my_put_u(va_list variables, int count, int arg_select);
int		my_put_x(va_list variables, int count, int arg_select);
int		my_put_X(va_list variables, int count, int arg_select);

int		(*ptr_func[9])(va_list, int, int) =
{
    my_put_no_flag,
    my_put_c,
    my_put_s,
    my_put_d,
    my_put_i,
    my_put_o,
    my_put_u,
    my_put_x,
    my_put_X
};

#endif		/* !_MY_PTR_FUNC_H_ */
