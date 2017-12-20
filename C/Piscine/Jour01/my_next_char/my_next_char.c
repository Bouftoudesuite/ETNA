/*
** my_next_char.c for  in /home/habi/Piscine1/C/Jour01/my_next_char
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Mon Sep 25 13:27:20 2017 HABI Acal
** Last update Mon Sep 25 13:27:20 2017 HABI Acal
*/
void    my_putchar(char c);

char    my_next_char(char c)
{
    int ascii;

    ascii = c;
    if ((ascii < 122 && ascii >= 97) || (ascii < 90 && ascii >= 65))
    {
        ascii++;
    }
    else if (ascii == 122)
    {
        ascii = 97;
    }
    else if (ascii == 90)
    {
        ascii = 65;
    }
    else
    {
	ascii = 32;
    }
    return (ascii);
}
