int	my_nbrlen(int n)
{
    int	i;

    i = 1;
    while (n > 9)
    {
        n /= 10;
        i++;
    }
    return (i);
}

