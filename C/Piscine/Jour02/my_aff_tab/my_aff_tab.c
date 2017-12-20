/*
** my_aff_tab.c for  in /home/habi/Piscine1/C/Jour02/my_aff_tab
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Sep 26 09:21:10 2017 HABI Acal
** Last update Tue Sep 26 09:31:49 2017 HABI Acal
*/
void    my_putchar(char c);

void    my_aff_tab(char str[])
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
	++i;
    }
}
