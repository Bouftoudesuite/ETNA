#include <check.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

t_bool path_exist(const char *path)
{
    int exist;
    struct stat buffer;

    exist = stat(path, &buffer);
    if (exist == -1)
        return false;
    else
        return true;
}

t_bool is_file(const char *path)
{
    struct stat buffer;

    stat(path, &buffer);
    return ((t_bool)S_ISREG(buffer.st_mode));
}

t_bool is_dir(const char *path)
{
    struct stat buffer;

    stat(path, &buffer);
    return ((t_bool)S_ISDIR(buffer.st_mode));
}