#ifndef _FLAGS_H_
# define _FLAGS_H_

typedef struct s_node_flags
{
    char _key;
    void (*_ptr_func)(void);
    struct s_node_flags *_next;
} t_node_flags;

typedef struct s_list_flags
{
    unsigned int _size;
    t_node_flags *_first;
    t_node_flags *_last;
} t_list_flags;

void init_list_flags(t_list_flags *list);
void push_back_flag(t_list_flags *list, char key);
void fill_flags(int argc, char **argv, t_list_flags *list);
t_node_flags *get_flags(char key, t_list_flags *list);
void free_list_flags(t_list_flags *list);

#endif /* _FLAGS_H_ */
