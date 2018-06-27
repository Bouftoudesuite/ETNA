#include <check.h>
#include <flags.h>
#include <my.h>
#include <params.h>
#include <stdlib.h>

static void print_argv(t_list_params *list_params, t_node_params *param)
{
    if (list_params->_size > 1 && is_dir(param))
    {
        my_putstr(param->_path);
        my_putstr(":\n");
    }
}

static void print_argv_only(t_node_params *param)
{
    my_putstr(param->_path);
    my_putchar('\n');
}

static void print_error(t_node_params *param)
{
    my_putstr("./my_ls: ");
    my_putstr(param->_path);
    my_putstr(": No such file or directory\n");
}

int main(int argc, char **argv)
{
    char **to_ls;
    t_list_flags list_flags;
    t_list_params list_params;
    t_node_params *param;

    init_list_flags(&list_flags);
    init_list_params(&list_params);
    get_flags(argc, argv, &list_flags);
    get_params(argc, argv, &list_params);
    to_ls = malloc(list_params._size * sizeof(char));
    push_params_to_tab(to_ls, &list_params);
    /*param = list_params._first;
    while (param)
    {
        if (path_exist(param) && is_dir(param))
            print_argv(&list_params, param);
        else if (path_exist(param))
            print_argv_only(param);
        else
            print_error(param);
        my_putchar('\n');
        param = param->_next;
    }*/
    return (0);
}