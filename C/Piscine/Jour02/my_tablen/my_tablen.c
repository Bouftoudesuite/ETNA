/*
** my_tablen.c for  in /home/habi/Piscine1/C/Jour02/my_tablen
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Sep 26 11:00:54 2017 HABI Acal
** Last update Tue Sep 26 11:01:18 2017 HABI Acal
*/
int     my_tablen(char tab[])
{
    int size;

    size = 0;
    while (tab[size] != '\0')
    {
        ++size;
    }
    return (size);
}
