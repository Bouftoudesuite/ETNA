/*
** my_put_nbr.c for  in /home/habi/Piscine1/C/Jour05-06/my_put_nbr
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Fri Sep 29 14:19:52 2017 HABI Acal
** Last update Fri Sep 29 14:19:53 2017 HABI Acal
*/
void		my_putchar(char c);

void		my_put_un_nbr(unsigned int n)
{
    int		i;
    int		divisible;

    divisible = n / 10;
    i = n % 10;
    if (divisible != 0)
    {
        my_put_un_nbr(divisible);
    }
    my_putchar(i + '0');
}

void		my_put_nbr(int n)
{
    if (n < 0)
    {
        my_putchar('-');
        n *= (-1);
    }
    my_put_un_nbr(n);
}
