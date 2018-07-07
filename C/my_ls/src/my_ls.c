#include <check.h>
#include <flags.h>
#include <my_ls.h>
#include <print.h>
#include <results.h>
#include <sort.h>
#include <stdlib.h>
#include <tols.h>

static void run(t_list_flags *list_flags, const char *path, unsigned int argc, t_node_months **arr_months)
{
    char **resultab;
    t_list_results list_results;

    init_list_results(&list_results);
    fill_results(&list_results, path, list_flags);
    resultab = malloc(list_results._size * sizeof(char*));
    push_results_to_resultab(resultab, &list_results);
    if (get_flags('t', list_flags))
        sort_results_by_date(resultab, list_results._size, arr_months);
    if (get_flags('r', list_flags))
        my_revert_tab(resultab, list_results._size);
    print_argv(argc, path);
    print_results(resultab, list_results._size, list_flags);
    free_list_results(&list_results);
    free_resultab(resultab, list_results._size);
}

void my_ls(char **tols, unsigned int size, t_list_flags *list_flags, t_node_months **arr_months)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (path_exist(tols[i]) && is_dir(tols[i]) && !get_flags('d', list_flags))
            run(list_flags, tols[i], size, arr_months);
		else if (path_exist(tols[i]))
			print_argv_only(tols[i], list_flags);
		else
			print_error(tols[i]);
		i++;
	}
}
