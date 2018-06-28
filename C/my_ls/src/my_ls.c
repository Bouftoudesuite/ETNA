#include <check.h>
#include <my_ls.h>

static void print_argv(unsigned int size, const char *path)
{
	if (size > 1 && is_dir(path))
	{
		my_putstr(path);
		my_putstr(":\n");
	}
}

static void print_argv_only(const char *path)
{
	my_putstr(path);
	my_putchar('\n');
}

static void print_error(const char *path)
{
	my_putstr("my_ls: cannot access '");
	my_putstr(path);
	my_putstr("': No such file or directory\n");
}

void my_ls(t_list_flags *list_flags, char **tols, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (path_exist(tols[i]) && is_dir(tols[i]))
			print_argv(size, tols[i]);
		else if (path_exist(tols[i]))
			print_argv_only(tols[i]);
		else
			print_error(tols[i]);
		i++;
	}
}
