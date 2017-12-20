/*
** my_strupcase.c for  in /home/habi/Piscine1/C/Jour02/my_strupcase
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Sep 26 14:27:14 2017 HABI Acal
** Last update Tue Sep 26 14:33:16 2017 HABI Acal
*/
void    my_putchar(char c);

char    *my_strupcase(char str[])
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if ((str[i] >= 97) && (str[i] <= 122))
        {
	    str[i] -= 32;
        }
        ++i;
    }
    return (str);
}
