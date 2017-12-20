/*
** my_aff_tab_num.c for  in /home/habi/Piscine1/C/Jour02/my_aff_tab_num
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Sep 26 09:58:10 2017 HABI Acal
** Last update Tue Sep 26 09:58:22 2017 HABI Acal
*/
void    my_putchar(char c);

void    my_aff_tab_num(int tab[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        my_putchar(48 + tab[i]);
        my_putchar('\n');
        ++i;
    }
}
