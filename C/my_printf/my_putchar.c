/*
** my_putchar.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:19:50 2017 HABI Açal
** Last update Sat Jan  6 22:35:25 2018 HABI Açal
*/
#include <unistd.h>

void	my_putchar(char c)
{
    write(1, &c, 1);
}
