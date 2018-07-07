#include <check.h>
#include <flags.h>
#include <info.h>
#include <my.h>
#include <print.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void print_argv(unsigned int size, const char *path)
{
    if (size > 1 && is_dir(path))
    {
        my_putstr(path);
        my_putstr(":\n");
    }
}

void print_argv_only(const char *name, t_list_flags *list_flags)
{
    if (get_flags('l', list_flags))
    {
        print_info(name, list_flags);
        my_putchar(' ');
    }
    my_putstr(name);
    my_putchar('\n');
}

void print_error(const char *path)
{
    my_putstr("my_ls: cannot access '");
    my_putstr(path);
    my_putstr("': No such file or directory\n");
}

static void print_ll(const char *name, t_list_flags *list_flags)
{
    int size_buffer;
    struct stat buffer;
    char buffer_two[255];

    if (lstat(name, &buffer) == -1)
    {
        my_putstr("./my_ls: error lstat");
        return ;
    }
    print_info(name, list_flags);
    my_putchar('\t');
    my_putstr(name);
    if (S_ISLNK(buffer.st_mode) && !get_flags('L', list_flags))
    {
        size_buffer = (int)readlink(name, buffer_two, 254);
        buffer_two[size_buffer] = '\0';
        my_putstr(" -> ");
        my_putstr(buffer_two);
    }
    my_putchar('\n');
}

void print_results(char **resultab, unsigned int size, t_list_flags *list_flags)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (get_flags('l', list_flags))
            print_ll(resultab[i], list_flags);
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
