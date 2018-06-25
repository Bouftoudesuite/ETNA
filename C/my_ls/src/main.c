#include <flags.h>

int main(int argc, char **argv)
{
    t_list_flags list_flags;

    init_list_flags(&list_flags);
    get_flags(argc, argv, &list_flags);
    return (0);
}