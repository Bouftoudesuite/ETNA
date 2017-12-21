/*
** my_sort_int_tab.c for  in /home/habi/Piscine1/C/Jour04/my_sort_int_tab
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Sep 28 09:19:36 2017 HABI Acal
** Last update Thu Sep 28 09:19:38 2017 HABI Acal
*/
void	my_sort_int_tab(int *tab, int size)
{
    int i;
    int j;
    int vide;
    int little;

    i = 0;
    j = 0;
    little = 0;
    while (j < size)
    {
        while (i < size)
    	{
      	    if (*(tab + little) > *(tab + i))
      	    {
                little = i;
      	    }
      	    i++;
    	}
    	vide = *(tab + j);
	*(tab + j) = *(tab + little);
	*(tab + little) = vide;
    	j++;
    	little = j;
    	i = little;
    }
}
