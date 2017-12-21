/*
** my_putstr.c for  in /home/habi/Piscine1/C/Jour03/my_putstr
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Sep 27 09:47:18 2017 HABI Acal
** Last update Wed Sep 27 09:47:21 2017 HABI Acal
*/
void    my_putchar(char c);

void    my_putstr(char *str)
{
    int i;

    i = 0;
    while (*(str + i) != '\0')
    {
        my_putchar(*(str + i));
        ++i;
    }
}
