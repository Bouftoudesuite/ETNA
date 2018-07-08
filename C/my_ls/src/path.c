#include <my.h>
#include <stdlib.h>

char *get_fullpath(const char *filename, const char *directory)
{
    char *full_path;
    unsigned int len;

    full_path = malloc(255 * sizeof(char));
    if (full_path == NULL)
        return (NULL);
    my_strcpy(full_path, directory);
    len = my_strlen(full_path);
    if (full_path[len - 1] != '/')
    {
        full_path[len] = '/';
        full_path[len + 1] = '\0';
    }
    my_strcat(full_path, filename);
    return (full_path);
}