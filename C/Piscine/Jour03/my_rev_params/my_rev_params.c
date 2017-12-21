/*
** my_rev_params.c for  in /home/habi/Piscine1/C/Jour03/my_rev_params
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Sep 27 17:52:10 2017 HABI Acal
** Last update Wed Sep 27 17:52:11 2017 HABI Acal
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

void    my_rev_params(int nbr, char **arg)
{
    int i;

    i = 0;
    while (--nbr >= 0)
    {
        my_putstr(arg[nbr]);
        my_putchar('\n');
        --i;
    }
}
