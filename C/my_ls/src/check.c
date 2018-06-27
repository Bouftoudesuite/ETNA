#include <check.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

t_bool path_exist(t_node_params *param)
{
    int exist;
    struct stat buffer;

    exist = stat(param->_path, &buffer);
    if (exist == -1)
        return false;
    else
        return true;
};

t_bool is_file(t_node_params *param)
{
    struct stat buffer;

    stat(param->_path, &buffer);
    return ((t_bool)S_ISREG(buffer.st_mode));
}

t_bool is_dir(t_node_params *param)
{
    struct stat buffer;

    stat(param->_path, &buffer);
    return ((t_bool)S_ISDIR(buffer.st_mode));
}