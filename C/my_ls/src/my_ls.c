/*
** my_ls.c for my_ls in /Users/habi_a/Documents/ETNA/C/my_ls
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Mon Mar 19 11:24:00 2018 HABI Açal
** Last update Mon Mar 19 11:42:01 2018 HABI Açal
*/
#include <dirent.h>
#include <my.h>
#include <stdlib.h>

int						my_ls(const char *path)
{
	struct dirent		*d;
	DIR					*dir;

	dir = opendir(path);
	if (dir == NULL)
		return (0);
	while (( d = readdir(dir)))
	{
		my_putstr(d->d_name);
		my_putchar('\n');
	}
	return (0);
}