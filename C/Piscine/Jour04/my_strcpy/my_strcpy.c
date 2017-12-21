/*
** my_strcpy.c for  in /home/habi/Piscine1/C/Jour04/my_strcpy
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Sep 28 10:03:47 2017 HABI Acal
** Last update Thu Sep 28 10:03:49 2017 HABI Acal
*/
char    *my_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (*(src + i) != '\0')
    {
        *(dest + i) = *(src + i);
	++i;
    }
    *(dest + i) = '\0';
    return (dest);
}
