#include <check.h>
#include <flags.h>
#include <my_ls.h>
#include <print.h>
#include <results.h>
#include <stdlib.h>
#include <tols.h>

static void run(t_list_flags *list_flags, const char *path, unsigned int argc)
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
			print_argv_only(tols[i], list_flags);
		else
			print_error(tols[i]);
		i++;
	}
}
