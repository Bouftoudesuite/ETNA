#include <check.h>
#include <flags.h>
#include <my_ls.h>
#include <path.h>
#include <print.h>
#include <results.h>
#include <sort.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <tols.h>

static unsigned int get_nb_directory(char **resultab, unsigned int result_size, const char *pwd)
{
    unsigned int i;
    unsigned int new_size;
    char* full_path;

    i = 0;
    new_size = 0;
    while (i < result_size)
    {
        full_path = get_fullpath(resultab[i], pwd);
        if (is_dir(full_path) && my_strcmp(".", resultab[i]) && my_strcmp("..", resultab[i]))
            new_size++;
        free(full_path);
        i++;
    }
    return (new_size);
}

static void recursivity(char **resultab, unsigned int result_size, const char *pwd, t_list_flags *list_flags, t_node_months **arr_months)
{
    unsigned int i;
    unsigned int new_size;
    char **new_tols;

    new_size = get_nb_directory(resultab, result_size, pwd);
    new_tols = malloc(new_size * sizeof(char*));
    i = push_resultab_to_newtols(new_tols, resultab, result_size, pwd);
    if (i > 0)
    {
        push_back_flag(list_flags, '&');
        if (get_flags('t', list_flags))
            sort_results_by_date(new_tols, new_size, list_flags, arr_months, "./");
        if (get_flags('r', list_flags))
            my_revert_tab(new_tols, new_size);
        my_ls(new_tols, new_size, list_flags, arr_months);
    }
    free_tab(new_tols, new_size);
}

static void print_total(char **resultab, unsigned int size, const char *pwd, t_list_flags *list_flags)
{
    char *full_path;
    unsigned int i;
    unsigned int total;
    struct stat buffer;

    i = 0;
    total = 0;
    while (i < size)
    {
        full_path = get_fullpath(resultab[i], pwd);
        (!get_flags('L', list_flags)) ? lstat(full_path, &buffer) : stat(full_path, &buffer);
        if (resultab[i][0] != '.' || get_flags('a', list_flags))
            total += buffer.st_blocks;
        else if (my_strcmp(resultab[i], ".") && my_strcmp(resultab[i], "..") && get_flags('A', list_flags))
            total += buffer.st_blocks;
        free(full_path);
        i++;
    }
    if (i > 0)
    {
        my_putstr("total ");
        my_putnbr(total / 2);
        my_putchar('\n');
    }
}

static void run(t_list_flags *list_flags, const char *path, unsigned int argc, t_node_months **arr_months)
{
    char **resultab;
    t_list_results list_results;

    init_list_results(&list_results);
    fill_results(&list_results, path, list_flags);
    resultab = malloc(list_results._size * sizeof(char*));
    if (resultab == NULL)
        return ;
    push_results_to_resultab(resultab, &list_results);
    if (get_flags('t', list_flags) && list_results._size > 0)
        sort_results_by_date(resultab, list_results._size, list_flags, arr_months, path);
    if (get_flags('r', list_flags) && list_results._size > 0)
        my_revert_tab(resultab, list_results._size);
    print_argv(argc, path, list_flags);
    if (get_flags('l', list_flags))
        print_total(resultab,list_results._size, path, list_flags);
    print_results(resultab, list_results._size, list_flags, path);
    if (get_flags('R', list_flags))
        recursivity(resultab, list_results._size, path, list_flags, arr_months);
    free_list_results(&list_results);
    free_tab(resultab, list_results._size);
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
