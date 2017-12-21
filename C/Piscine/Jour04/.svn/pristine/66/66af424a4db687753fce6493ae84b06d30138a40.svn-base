/*
** my_strncmp.c for  in /home/habi/Piscine1/C/Jour04/my_strncmp
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Thu Sep 28 14:37:43 2017 HABI Acal
** Last update Thu Sep 28 20:44:52 2017 HABI Acal
*/
int     my_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while (*(s1 + i) != '\0' && *(s2 + i) != '\0'
		&& *(s1 + i) == *(s2 + i) && i < n
		&& *(s1 + i) && *(s2 + i))
    {
        ++i;
    }
    if (i < n)
    {
        return (*(s1 + i) - *(s2 + i));
    }
    return (0);
}
