#include <check.h>
#include <chmod.h>
#include <my.h>
#include <print.h>

void print_argv(unsigned int size, const char *path)
{
    if (size > 1 && is_dir(path))
    {
        my_putstr(path);
        my_putstr(":\n");
    }
}

void print_argv_only(const char *path)
{
    my_putstr(path);
    my_putchar('\n');
}

void print_error(const char *path)
{
    my_putstr("my_ls: cannot access '");
    my_putstr(path);
    my_putstr("': No such file or directory\n");
}

static void print_ll(const char *name)
{
    print_chmod(name);
    my_putchar('\t');
    my_putstr(name);
    my_putchar('\n');
}

void print_results(char **resultab, unsigned int size, t_list_flags *list_flags)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (get_flags('l', list_flags))
            print_ll(resultab[i]);
        else
        {
            my_putstr(resultab[i]);
            my_putchar('\t');
        }
        i++;
    }
    if (get_flags('l', list_flags))
        my_putchar('\n');
    my_putchar('\n');
}
