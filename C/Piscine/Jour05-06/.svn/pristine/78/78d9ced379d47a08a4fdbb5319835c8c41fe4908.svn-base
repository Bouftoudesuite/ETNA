/*
** my_getnbr.c for  in /home/habi/Piscine1/C/Jour05-06/my_getnbr
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Fri Sep 29 15:40:10 2017 HABI Acal
** Last update Fri Sep 29 15:40:12 2017 HABI Acal
*/
void    my_putchar(char c);

int     my_getsigne(char *str, int *pointeur)
{
    int pos_neg;
    int k;

    k = 0;
    pos_neg = 1;
    while (*(str + k) == '-' || *(str + k) == '+')
    {
	if (*(str + k) == '+')
        {
            pos_neg *= 1;
        }
        if (*(str + k) == '-')
        {
            pos_neg *= (-1);
        }
        ++k;
    }
    *pointeur = k;
    return (pos_neg);
}

int     my_getnbr(char *str)
{
    int signe;
    int n;
    int i;
    int *pointeur = &i;

    i = 0;
    n = 0;
    signe = my_getsigne(str, pointeur);
    while (*(str + i) != '\0')
    {
        if (*(str + i) >= '0' && *(str + i) <= '9')
        {
            n *= 10;
            n += *(str + i);
            n -= '0';
            ++i;
        }
        else
        {
            return (n * signe);
        }
    }
    return (n * signe);
}
