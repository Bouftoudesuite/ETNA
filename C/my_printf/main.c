/*
** main.c for my_printf in /cygdrive/c/Users/Habi/Documents/ETNA/C/my_printf
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Tue Dec 26 13:34:00 2017 HABI Açal
** Last update Tue Dec 26 13:34:01 2017 HABI Açal
*/
int	my_printf(const char * restrict str, ...);
void	my_put_nbr(int n);

int	main(int argc, char const *argv[])
{
    my_printf("Voici une lettre: %c\n
		Voici une addition: %d + %i = %d\n
		Voici une chaine de caractere: %s\n
		Voici un pourcentage: 100%%\n",
		'A', 2, 3, 2 + 3, "Hello Word!");
    return 0;
}
