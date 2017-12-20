/*
** my_strlowcase.c for  in /home/habi/Piscine1/C/Jour02/my_strlowcase
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Sep 26 14:57:37 2017 HABI Acal
** Last update Tue Sep 26 15:00:38 2017 HABI Acal
*/
void    my_putchar(char c);

char    *my_strlowcase(char str[])
{
  int i;

  i = 0;
  while(str[i] != '\0')
    {
      if ((str[i] >= 65) && (str[i] <= 90))
	{
	  str[i] += 32;
	}
      ++i;
    }
  return (str);
}
