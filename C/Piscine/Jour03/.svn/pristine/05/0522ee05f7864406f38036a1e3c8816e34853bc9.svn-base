/*
** my_put_revstr.c for  in /home/habi/Piscine1/C/Jour03/my_put_revstr
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Sep 27 13:06:45 2017 HABI Acal
** Last update Wed Sep 27 13:06:58 2017 HABI Acal
*/
void    my_putchar(char c);

int     my_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }
    return (i);
}

void    my_put_revstr(char *str)
{
    int i;

    i = my_strlen(str);
    while (i >= 0)
    {
        my_putchar(*(str + i));
        --i;
    }
}
