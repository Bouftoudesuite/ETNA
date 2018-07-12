/*
** path.c for my_ls in /Users/habi_a/Documents/ETNA/C
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Thu Jul 12 17:11:26 2018 HABI Açal
*/
#include <my.h>
#include <stdlib.h>

char			*get_fullpath(const char *filename,
				      const char *directory)
{
    char		*full_path;
    unsigned int	len;

    len = my_strlen(directory);
    if (directory[len - 1] != '/')
    {
        full_path = malloc((my_strlen(filename) + my_strlen(directory) + 2) *
			   sizeof(char));
        if (full_path == NULL)
            return (NULL);
        my_strcpy(full_path, directory);
        full_path[len] = '/';
        full_path[len + 1] = '\0';
    }
    else
    {
        full_path = malloc((my_strlen(filename) + my_strlen(directory) + 1) *
			   sizeof(char));
        if (full_path == NULL)
            return (NULL);
        my_strcpy(full_path, directory);
    }
    my_strcat(full_path, filename);
    return (full_path);
}
