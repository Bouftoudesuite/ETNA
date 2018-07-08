#include <months.h>
#include <my.h>
#include <stdlib.h>

void init_arr_month(t_node_months **arr_month)
{
    unsigned int i;

    i = 0;
    while (i < M_NUMBER)
    {
        arr_month[i] = malloc(sizeof(t_node_months));
        if (arr_month[i] == NULL)
            return ;
        i++;
    }
}

void fill_arr_months(t_node_months **arr_month)
{
    arr_month[0]->_key = "Jan";
    arr_month[0]->_value = "01";
    arr_month[1]->_key = "Feb";
    arr_month[1]->_value = "02";
    arr_month[2]->_key = "Mar";
    arr_month[2]->_value = "03";
    arr_month[3]->_key = "Apr";
    arr_month[3]->_value = "04";
    arr_month[4]->_key = "May";
    arr_month[4]->_value = "05";
    arr_month[5]->_key = "Jun";
    arr_month[5]->_value = "06";
    arr_month[6]->_key = "Jul";
    arr_month[6]->_value = "07";
    arr_month[7]->_key = "Aug";
    arr_month[7]->_value = "08";
    arr_month[8]->_key = "Sep";
    arr_month[8]->_value = "09";
    arr_month[9]->_key = "Oct";
    arr_month[9]->_value = "10";
    arr_month[10]->_key = "Nov";
    arr_month[10]->_value = "11";
    arr_month[11]->_key = "Dec";
    arr_month[11]->_value = "12";
}

t_node_months *get_months(const char *key, t_node_months **arr_month)
{
    unsigned int i;

    i = 0;
    while (arr_month[i])
    {
        if (!my_strcmp(arr_month[i]->_key, key))
            return (arr_month[i]);
        i++;
    }
    return (NULL);
}

void free_arr_months(t_node_months **arr_months)
{
    unsigned int i;

    i = 0;
    while (i < M_NUMBER)
    {
        free(arr_months[i]);
        i++;
    }
    free(arr_months);
}
