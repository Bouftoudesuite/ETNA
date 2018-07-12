#include <flags.h>
#include <months.h>
#include <my.h>
#include <my_ls.h>
#include <params.h>
#include <sort.h>
#include <stdlib.h>
#include <tols.h>

static void init(t_list_flags *list_flags, t_list_params *list_params, t_node_months **arr_months)
{
    init_list_flags(list_flags);
    init_list_params(list_params);
    init_arr_month(arr_months);
}

static void fill_list(t_list_flags *list_flags, t_list_params *list_params, int argc, char **argv)
{
    fill_flags(argc, argv, list_flags);
    fill_params(argc, argv, list_params);
}

static void sort_tols(char **tols, unsigned int size, t_list_flags *list_flags, t_node_months **arr_months)
{
    char *pwd;

    pwd = my_strdup("./");
    sort_tols_by_type(tols, size, list_flags);
    if (!get_flags('t', list_flags))
    {
        if (!get_flags('r', list_flags))
            sort_tols_by_alpha(tols, size, list_flags);
        else
            sort_tols_by_alpha_rev(tols, size, list_flags);
    }
    else
    {
        if (!get_flags('r', list_flags))
            sort_tols_by_date(tols, size, list_flags, arr_months, pwd);
        else
            sort_tols_by_date_rev(tols, size, list_flags, arr_months, pwd);
    }
    free(pwd);
}

static void free_ptr(t_list_flags *list_flags, t_list_params *list_params, t_node_months **arr_months)
{
    free_list_flags(list_flags);
    free_list_params(list_params);
    free_arr_months(arr_months);
}

int main(int argc, char **argv)
{
    char **tols;
    t_list_flags list_flags;
    t_list_params list_params;
    t_node_months **arr_months;

    arr_months = malloc(M_NUMBER * sizeof(t_node_months*));
    if (arr_months == NULL)
        return (1);
    init(&list_flags, &list_params, arr_months);
    fill_list(&list_flags, &list_params, argc, argv);
    fill_arr_months(arr_months);
    tols = malloc(list_params._size * sizeof(char*));
    push_params_to_tols(tols, &list_params);
    if (!get_flags('U', &list_flags))
        sort_tols(tols, list_params._size, &list_flags, arr_months);
    my_ls(tols, list_params._size, &list_flags, arr_months);
    free_ptr(&list_flags, &list_params, arr_months);
    free_tab(tols, list_params._size);
    return (0);
}
