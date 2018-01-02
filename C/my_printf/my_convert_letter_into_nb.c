/*
** my_convert_letter_into_nb.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:20:53 2017 HABI Açal
** Last update Tue Jan  2 21:10:11 2018 HABI Açal
*/
int		my_convert_letter_into_nb(char letter)
{
    int		i;
    char	flags[9] = {'%', 'c', 's', 'd', 'i', 'o', 'u', 'x', 'X'};

    i = 0;
    while (flags[i] != '\0')
    {
        if (flags[i] == letter)
            return (i);
        i++;
    }
    return (9);
}
