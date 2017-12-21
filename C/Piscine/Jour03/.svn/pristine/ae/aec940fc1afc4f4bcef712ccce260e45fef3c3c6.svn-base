/*
** my_aff_params.c for  in /home/habi/Piscine1/C/Jour03/my_aff_params
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Sep 27 16:59:51 2017 HABI Acal
** Last update Wed Sep 27 16:59:55 2017 HABI Acal
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

void    my_aff_params(int nbr, char **arg)
{
    int	i;

    i = 0;
    while (i < nbr)
    {
        my_putstr(arg[i]);
        my_putchar('\n');
        ++i;
    }
}
