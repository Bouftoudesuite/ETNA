/*
** my_strncpy.c for  in /home/habi/Piscine1/C/Jour04/my_strncpy
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Sep 28 10:18:04 2017 HABI Acal
** Last update Thu Sep 28 10:18:17 2017 HABI Acal
*/
char    *my_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while (*(src + i) != '\0' && n > 0)
    {
        *(dest + i) = *(src + i);
        ++i;
	--n;
    }
    *(dest + i) = '\0';
    return (dest);
}
