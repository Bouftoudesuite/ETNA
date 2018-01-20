/*
** my_putchar.c for  in /home/habi/Piscine1/C/Jour01/my_putchar
**
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Mon Sep 25 13:27:20 2017 HABI Acal
** Last update Mon Sep 25 13:28:48 2017 HABI Acal
*/
#include <unistd.h>

void    my_putchar(char c)
{
    write(1, &c, 1);
}