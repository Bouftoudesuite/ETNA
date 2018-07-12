/*
** date.c for my_ls in /Users/habi_a/Documents/ETNA/C
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Fri Apr  6 10:02:16 2018 HABI Açal
** Last update Thu Jul 12 17:41:14 2018 HABI Açal
*/
#include <date.h>
#include <my.h>
#include <path.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

static char	*format_date(t_node_months **arr_month, char *time)
{
    char	*month;
    char	*month_g;
    char	*rest;
    char	*result;

    month = my_strndup(time, 3);
    month_g = (char*)get_months(month, arr_month)->_value;
    rest = my_strrdup(time, 3);
    result = malloc(21 * sizeof(char));
    if (result == NULL)
        return (NULL);
    my_strcpy(result, month_g);
    my_strcat(result, rest);
    result[3] = (result[3] == ' ') ? '0' : result[3];
    free(month);
    free(rest);
    return (result);
}

static int	help_format_date(struct stat *buffer, struct stat *buffer_two,
				 t_node_months **arr_month, int result)
{
    char	*time;
    char	*time_two;
    char	*result_one;
    char	*result_two;

    time = my_strrdup(ctime(&buffer->st_mtime), 4);
    time_two = my_strrdup(ctime(&buffer_two->st_mtime), 4);
    result_one = format_date(arr_month, time);
    result_two = format_date(arr_month, time_two);
    result = my_strcmp(result_one, result_two);
    free(time);
    free(time_two);
    free(result_one);
    free(result_two);
    return (result);
}

int		strcmp_date(const char *path, const char *path_two,
			    const char *pwd, t_node_months **arr_month,
			    t_list_flags *list_flags)
{
    int		result;
    char	*full_path;
    char	*full_path_two;
    struct stat	buffer;
    struct stat	buffer_two;

    result = 0;
    full_path = get_fullpath(path, pwd);
    full_path_two = get_fullpath(path_two, pwd);
    (!get_flags('L', list_flags)) ?
      lstat(full_path, &buffer) : stat(full_path, &buffer);
    (!get_flags('L', list_flags)) ?
      lstat(full_path_two, &buffer_two) : stat(full_path_two, &buffer_two);
    result = help_format_date(&buffer, &buffer_two, arr_month, result);
    free(full_path);
    free(full_path_two);
    return (result);
}
