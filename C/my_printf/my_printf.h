/*
** my_printf.h for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 14:17:41 2017 HABI Açal
** Last update Thu Jan  4 21:39:27 2018 HABI Açal
*/
#ifndef		_MY_PRINTF_H_
#define		_MY_PRINTF_H_

#include	<stdarg.h>

void		my_putstr(const char *str);
int		my_strlen(const char *str);
int		my_nbrlen(int n);
int		my_convert_letter_into_nb(char letter);
void		my_flags_in_array(char *flags);
int		*my_pos_pourcent(const char *str);
char		*my_check_pourcent(const char *str, int *positions);
int		*my_pos_pourcent_help(const char *str, int *positions);
int		my_printf(const char *format, ...);
void		my_putchar(char c);
void		my_putstr(const char *str);
void		my_put_nbr(int n);
void		my_put_un_nbr(unsigned int n);
void		my_put_nbr_base(int n, char *base);
int		my_put_no_flag(va_list variables, int count, int arg_select);
int		my_put_c(va_list variables, int count, int arg_select);
int		my_put_i(va_list variables, int count, int arg_select);
int		my_put_d(va_list variables, int count, int arg_select);
int		my_put_s(va_list variables, int count, int arg_select);
int		my_put_o(va_list variables, int count, int arg_select);
int		my_put_u(va_list variables, int count, int arg_select);
int		my_put_x(va_list variables, int count, int arg_select);
int		my_put_X(va_list variables, int count, int arg_select);
int		my_ptr_func(va_list variables, int count, int arg_select, char letter);
int		my_str_print_help(const char *str, int i, int count);
int		my_str_print(const char *str, int *positions, char *letters,
			     va_list variables);

#endif		/* !_MY_PRINTF_H_ */