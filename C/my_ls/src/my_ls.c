#include <check.h>
#include <flags.h>
#include <my_ls.h>
#include <results.h>
#include <sort.h>
#include <stdlib.h>
#include <tols.h>

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

static void print_results(char **resultab, unsigned int size, t_list_flags *list_flags)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (get_flags('l', list_flags))
        {
            ;
        }
        my_putstr(resultab[i]);
        my_putchar('\t');
        i++;
    }
    my_putstr("\n\n");
}

void run(t_list_flags *list_flags, const char *path, unsigned int argc)
{
    char **resultab;
    t_list_results list_results;

    init_list_results(&list_results);
    fill_results(&list_results, path, list_flags);
    resultab = malloc(list_results._size * sizeof(char*));
    push_results_to_resultab(resultab, &list_results);
    if (get_flags('r', list_flags))
        my_sort_rev_str_tab(resultab, list_results._size);
    print_argv(argc, path);
    print_results(resultab, list_results._size, list_flags);
    free_list_results(&list_results);
    free_resultab(resultab, list_results._size);
}

void my_ls(char **tols, unsigned int size, t_list_flags *list_flags)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (path_exist(tols[i]) && is_dir(tols[i]) && !get_flags('d', list_flags))
            run(list_flags, tols[i], size);
		else if (path_exist(tols[i]))
			print_argv_only(tols[i]);
		else
			print_error(tols[i]);
		i++;
	}
}
