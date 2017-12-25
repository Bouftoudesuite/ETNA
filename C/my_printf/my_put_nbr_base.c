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
