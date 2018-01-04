/*
** my_strlen.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:23:07 2017 HABI Açal
** Last update Thu Jan  4 21:08:25 2018 HABI Açal
*/
int	my_strlen(const char *str)
{
    int	i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}
