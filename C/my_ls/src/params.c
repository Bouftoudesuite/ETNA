#include <my.h>
#include <params.h>
#include <stdlib.h>
#include <unistd.h>

void init_list_params(t_list_params *list)
{
    list->_size = 0;
    list->_first = NULL;
    list->_last = NULL;
}

void push_back_param(t_list_params *list, const char *path)
{
    t_node_params *new_element;

    new_element = malloc(sizeof(t_node_params));
    if (new_element == NULL || list == NULL)
    {
        free(new_element);
        free(list);
        return ;
    }
    new_element->_path = path;
    new_element->_next = NULL;
    list->_size++;
    if (list->_last != NULL)
        list->_last->_next = new_element;
    else
        list->_first = new_element;
    list->_last = new_element;
}

void get_params(int argc, char **argv, t_list_params *list)
{
    int i;

    i = 0;
    while (i < argc)
    {
        if (argv[i][0] != '-' && i)
            push_back_param(list, argv[i]);
        i++;
    }
    if (argc == 1)
        push_back_param(list, "./");
}

static void push_string(const char *src, char *dest)
{
    int len;

    len = my_strlen(src) + 1;
    dest = malloc((unsigned)len);
    if(dest == NULL)
        return ;
    dest = my_strcpy(dest, src);
    dest[len - 1] = '\0';
}

void push_params_to_tab(char **to_ls, t_list_params *list)
{
    unsigned int i;
    t_node_params *param;

    i = 0;
    param = list->_first;
    while (i < list->_size && param)
    {
        push_string(param->_path, to_ls[i]);
        param->_next;
        i++;
    }
}
