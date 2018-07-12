/*
** check.c for my_ls in /Users/habi_a/Documents/ETNA/C
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Fri Apr  6 10:02:21 2018 HABI Açal
*/
#include <check.h>
#include <sys/types.h>
#include <sys/stat.h>

t_bool is_dir(const char *path)
{
    struct stat buffer;

    stat(path, &buffer);
    return ((t_bool)S_ISDIR(buffer.st_mode));
}

t_bool is_file(const char *path)
{
    struct stat buffer;

    stat(path, &buffer);
    return ((t_bool)S_ISREG(buffer.st_mode));
}

t_bool is_same_type(const char *path_one, const char *path_two)
{
    return ((t_bool)((is_dir(path_one) && is_dir(path_two)) ||
            (is_file(path_one) && is_file(path_two)) ||
            (!path_exist(path_one) && !path_exist(path_two))));
}

t_bool path_exist(const char *path)
{
    int exist;
    struct stat buffer;

    exist = stat(path, &buffer);
    if (exist == -1)
        return (false);
    else
        return (true);
}
