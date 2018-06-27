#include <check.h>
#include <flags.h>
#include <stdlib.h>

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
    my_putstr("./my_ls: ");
    my_putstr(path);
    my_putstr(": No such file or directory\n");
}

int main(int argc, char **argv)
{
    char **to_ls;
    unsigned int i;
    t_list_flags list_flags;
    t_list_params list_params;

    init_list_flags(&list_flags);
    init_list_params(&list_params);
    get_flags(argc, argv, &list_flags);
    get_params(argc, argv, &list_params);
    to_ls = malloc(list_params._size * sizeof(char));
    push_params_to_tab(to_ls, &list_params);
    sort_param_by_type(to_ls, list_params._size);
    i = 0;
    while (i < list_params._size)
    {
        if (path_exist(to_ls[i]) && is_dir(to_ls[i]))
            print_argv(list_params._size, to_ls[i]);
        else if (path_exist(to_ls[i]))
            print_argv_only(to_ls[i]);
        else
            print_error(to_ls[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}