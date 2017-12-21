/*
** my_strlen.c for  in /home/habi/Piscine1/C/Jour03/my_strlen
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Wed Sep 27 09:34:02 2017 HABI Acal
** Last update Wed Sep 27 09:41:39 2017 HABI Acal
*/
int     my_strlen(char *str)
{
    int i;

    i = 0;
    while (*(str + i) != '\0')
    {
        ++i;
    }
    return (i);
}
