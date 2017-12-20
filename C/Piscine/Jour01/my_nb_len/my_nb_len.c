/*
** my_nb_len.c for  in /home/habi/Piscine1/C/Jour01/my_nb_len
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Mon Sep 25 16:34:09 2017 HABI Acal
** Last update Mon Sep 25 16:37:55 2017 HABI Acal
*/
void    my_putchar(char c);

int     my_nb_len(int n)
{
    int length;

    length = 0;
    if ( n == 0 )
    {
        length = 1;
    }
    while (n)
    {
        length++;
        n /= 10;
    }
    return (length);
}
