/*
** my_str_is_printable.c for  in /home/habi/Piscine1/C/Jour02/my_str_is_printable
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Sep 26 15:13:29 2017 HABI Acal
** Last update Tue Sep 26 15:13:39 2017 HABI Acal
*/
int        my_str_is_printable(char str[])
{
    int    i;
    int    printable;

    printable = 1;
    i = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 97 && str[i] <= 122)
		|| (str[i] >= 65 && str[i] <= 90) || (str[i] == 32)
		|| (str[i] == 40) || (str[i] == 41)))
        {
            printable = 0;
        }
        ++i;
    }
    if (printable)
        return (1);
    else
        return (0);
}
