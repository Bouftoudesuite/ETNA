#include <dirent.h>
#include <my.h>
#include <results.h>
#include <stdlib.h>

void init_list_results(t_list_results *list)
{
    list->_size = 0;
    list->_first = NULL;
    list->_last = NULL;
}

void push_back_result(t_list_results *list, const char *path)
{
    t_node_results *new_element;

    new_element = malloc(sizeof(t_node_results));
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

void fill_results(t_list_results *list_results, const char *path, t_list_flags *list_flags)
{
    struct dirent		*d;
    DIR					*dir;

    dir = opendir(path);
    if (dir == NULL)
        return;
    while ((d = readdir(dir)))
    {

        if (d->d_name[0] != '.' || get_flags('a', list_flags))
            push_back_result(list_results, my_strdup(d->d_name));
    }
    closedir(dir);
}

void free_list_results(t_list_results *list)
{
    t_node_results *tmp;
    t_node_results *p_elem;

    if (list == NULL)
        return ;
    p_elem = list->_first;
    while (p_elem != NULL)
    {
        tmp = p_elem;
        p_elem = p_elem->_next;
        free((char*)tmp->_path);
        free(tmp);
    }
    list->_first = NULL;
    list->_last = NULL;
}
