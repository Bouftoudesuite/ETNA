/*
** my_trspos_tab.c for  in /home/habi/Piscine1/C/Jour03/my_trspos_tab
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Sep 27 13:45:43 2017 HABI Acal
** Last update Wed Sep 27 16:46:26 2017 HABI Acal
*/
void    my_putchar(char c);

void    my_trspos_tab(int c, int l, char **tab)
{
    int	j;

    j = 0;
    while (c > 0)
    {
        --c;
        while (j < l)
        {
	    my_putchar(tab[j][c]);
	    ++j;
        }
        j = 0;
        my_putchar('\n');
    }
}
