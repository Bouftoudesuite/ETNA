/*
** my_put_nbr_base.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:22:38 2017 HABI Açal
** Last update Tue Dec 26 13:22:39 2017 HABI Açal
*/
void		my_putchar(char c);
int		my_strlen(char *str);

void		my_put_nbr_base(int n, char *base)
{
    int		i;
    int		j;

    if (n < 0)
    {
        my_putchar('-');
        n *= (-1);
    }
    j = n % my_strlen(base);
    i = n / my_strlen(base);
    if (i > 0)
    {
        my_put_nbr_base(i, base);
    }
    my_putchar(*(base + j));
}
