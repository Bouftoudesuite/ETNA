/*
** my_putchar.c for my_ls in /Users/habi_a/Documents/ETNA/C/my_ls
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Mon Mar 19 11:34:58 2018 HABI Açal
** Last update Mon Mar 19 11:36:04 2018 HABI Açal
*/
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
