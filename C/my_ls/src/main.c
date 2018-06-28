#include <flags.h>
#include <my.h>
#include <my_ls.h>
#include <params.h>
#include <stdlib.h>
#include <tols.h>

int main(int argc, char **argv)
{
    char **tols;
    t_list_flags list_flags;
    t_list_params list_params;

    init_list_flags(&list_flags);
    init_list_params(&list_params);
    fill_flags(argc, argv, &list_flags);
    fill_params(argc, argv, &list_params);
    tols = malloc(list_params._size * sizeof(char*));
    push_params_to_tols(tols, &list_params);
    my_sort_str_tab(tols, list_params._size);
    sort_param_by_type(tols, list_params._size);
    my_ls(&list_flags, tols, list_params._size);
    free_list_flags(&list_flags);
    free_list_params(&list_params);
    free_tols(tols, list_params._size);
    return (0);
}