int		my_convert_letter_into_nb(char lettre)
{
    int		i;
    char	flags[9] = {'%', 'c', 's', 'd', 'i', 'o', 'u', 'x', 'X'};

    i = 0;
    while (flags[i] != '\0')
    {
        if (flags[i] == lettre)
            return (i);
        i++;
    }
    return (-1);
}
