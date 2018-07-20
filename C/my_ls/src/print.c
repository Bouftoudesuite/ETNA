/*
** print.c for my_ls in /Users/habi_a/Documents/ETNA/C
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Thu Jul 12 17:14:36 2018 HABI Açal
*/
#include <check.h>
#include <flags.h>
#include <info.h>
#include <path.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void			print_argv(unsigned int size, const char *path,
				   t_list_flags *list_flags)
{
    if (is_dir(path) && (size > 1 || get_flags('&', list_flags)))
    {
        my_putchar('\n');
        my_putstr(path);
        my_putstr(":\n");
    }
}

void			print_argv_only(const char *name,
					t_list_flags *list_flags)
{
    struct stat		buffer;

    if (get_flags('l', list_flags))
    {
        (!get_flags('L', list_flags)) ?
	  lstat(name, &buffer) : stat(name, &buffer);
        print_info(&buffer, list_flags);
        my_putchar(' ');
    }
    my_putstr(name);
    my_putchar('\n');
}

void			print_error(const char *path)
{
    my_putstr("my_ls: cannot access '");
    my_putstr(path);
    my_putstr("': No such file or directory\n");
}

static void		print_ll(const char *name, t_list_flags *list_flags,
				 const char *pwd)
{
    int			size_buffer;
    char		*full_path;
    char		buffer_two[255];
    struct stat		buffer;

    full_path = get_fullpath(name, pwd);
    (!get_flags('L', list_flags)) ? 
      lstat(full_path, &buffer) : stat(full_path, &buffer);
    print_info(&buffer, list_flags);
    my_putstr(name);
    if (S_ISLNK(buffer.st_mode) && !get_flags('L', list_flags))
    {
        size_buffer = (int)readlink(name, buffer_two, 254);
        buffer_two[size_buffer] = '\0';
        my_putstr(" -> ");
        my_putstr(buffer_two);
    }
    free(full_path);
}

void			print_results(char **resultab, unsigned int size,
				      t_list_flags *list_flags, const char *pwd)
{
    unsigned int	i;

    i = 0;
    while (i < size)
    {
        if (get_flags('l', list_flags))
        {
            print_ll(resultab[i], list_flags, pwd);
            my_putchar('\n');
        }
        else
        {
            my_putstr(resultab[i]);
            if (get_flags('1', list_flags))
                my_putchar('\n');
            else
                (get_flags('m', list_flags) && i != size - 1) ?
		  my_putstr(", ") : my_putchar('\t');
        }
        i++;
    }
    if (!get_flags('l', list_flags) && !get_flags('1', list_flags))
        my_putchar('\n');
}
