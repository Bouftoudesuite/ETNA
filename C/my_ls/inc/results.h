#ifndef _RESULTS_H_
#define _RESULTS_H_

#include <flags.h>

typedef struct s_node_results
{
    const char *_path;
    struct s_node_results *_next;
} t_node_results;

typedef struct s_list_results
{
    unsigned int _size;
    t_node_results *_first;
    t_node_results *_last;
} t_list_results;

void init_list_results(t_list_results *list);
void push_back_result(t_list_results *list, const char *path);
void fill_results(t_list_results *list_results, const char *path, t_list_flags *list_flags);
void free_list_results(t_list_results *list);

#endif //_RESULTS_H_
