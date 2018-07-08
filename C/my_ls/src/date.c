#include <date.h>
#include <my.h>
#include <path.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

static char *format_date(t_node_months **arr_month, char *time_one)
{
    char *month_one;
    char *month_one_g;
    char *rest_one;
    char *result_one;

    month_one = my_strndup(time_one, 3);
    month_one_g = (char*)get_months(month_one, arr_month)->_value;
    rest_one = my_strrdup(time_one, 3);
    result_one = malloc(21 * sizeof(char));
    my_strcpy(result_one, month_one_g);
    my_strcat(result_one, rest_one);
    result_one[3] = (result_one[3] == ' ') ? '0' : result_one[3];
    free(month_one);
    free(rest_one);
    return (result_one);
}

static int help_format_date(struct stat *buffer, struct stat *buffer_two, t_node_months **arr_month, int result)
{
    char *time_one;
    char *time_two;
    char *result_one;
    char *result_two;

    time_one = my_strrdup(ctime(&buffer->st_mtime), 4);
    time_two = my_strrdup(ctime(&buffer_two->st_mtime), 4);
    result_one = format_date(arr_month, time_one);
    result_two = format_date(arr_month, time_two);
    result = my_strcmp(result_one, result_two);
    free(time_one);
    free(time_two);
    free(result_one);
    free(result_two);
    return (result);
}

int strcmp_date(const char *path_one, const char *path_two, const char *pwd, t_node_months **arr_month, t_list_flags *list_flags)
{
    int result;
    struct stat buffer;
    struct stat buffer_two;
    char *full_path_one;
    char *full_path_two;

    result = 0;
    full_path_one = get_fullpath(path_one, pwd);
    full_path_two = get_fullpath(path_two, pwd);
    (!get_flags('L', list_flags)) ? lstat(full_path_one, &buffer) : stat(full_path_one, &buffer);
    (!get_flags('L', list_flags)) ? lstat(full_path_two, &buffer_two) : stat(full_path_two, &buffer_two);
    result = help_format_date(&buffer, &buffer_two, arr_month, result);
    free(full_path_one);
    free(full_path_two);
    return (result);
}
