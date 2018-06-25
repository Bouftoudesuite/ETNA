#include <flags.h>
#include <my.h>
#include <params.h>

int main(int argc, char **argv)
{
    t_list_flags list_flags;
    t_list_params list_params;
    t_node_params *path;

    init_list_flags(&list_flags);
    init_list_params(&list_params);
    get_flags(argc, argv, &list_flags);
    get_params(argc, argv, &list_params);
    path = list_params._first;
    while (path)
    {
        if (list_params._size > 1)
        {
            my_putstr(path->_key);
            my_putstr(":\n");
        }
        path = path->_next;
    }
    return (0);
}