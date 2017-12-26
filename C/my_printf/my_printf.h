/*
** my_printf.h for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 14:17:41 2017 HABI Açal
** Last update Tue Dec 26 14:52:51 2017 HABI Açal
*/
#ifndef		_MY_PRINTF_H_
#define		_MY_PRINTF_H_

#include	<stdarg.h>

void		my_putstr(const char *str);
int		my_strlen(const char *str);
int		my_nbrlen(int n);
int		my_convert_letter_into_nb(char lettre);
int		*my_pos_pourcent(const char *str);
char		*my_check_pourcent(const char *str, int *positions);
int		*my_pos_pourcent_bis(const char *str, int *positions);
int		my_str_print(const char *str, int *positions, char *lettres,
			     va_list variables);
int		my_printf(const char *format, ...);
void		my_putchar(char c);
void		my_putstr(const char *str);
void		my_put_nbr(int n);
void		my_put_un_nbr(unsigned int n);
void		my_put_nbr_base(int n, char *base);

#endif		/* !_MY_PRINTF_H_ */
