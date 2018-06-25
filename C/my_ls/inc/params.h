#ifndef _PARAMS_H_
# define _PARAMS_H_

typedef struct s_node_params
{
    char *_key;
    struct s_node_params *_next;
} t_node_params;

typedef struct s_list_params
{
    unsigned int _size;
    t_node_params *_first;
    t_node_params *_last;
} t_list_params;

void init_list_params(t_list_params *list);
void push_back_param(t_list_params *list, char *key);
void get_params(int argc, char **argv, t_list_params *list);

#endif //_PARAMS_H_
