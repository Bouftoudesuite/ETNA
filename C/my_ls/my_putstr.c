/*
** my_putstr.c for my_ls in /Users/habi_a/Documents/ETNA/C/my_ls
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Mon Mar 19 11:36:13 2018 HABI Açal
** Last update Mon Mar 19 11:38:54 2018 HABI Açal
*/
void	my_putchar(char c);

void	my_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i++;
	}
}
