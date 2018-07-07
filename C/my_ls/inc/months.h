#ifndef _MONTHS_H_
# define _MONTHS_H_

# define M_NUMBER 12

typedef struct s_node_months
{
    const char *_key;
    const char *_value;
} t_node_months;

void init_arr_month(t_node_months **arr_month);
void fill_arr_months(t_node_months **arr_month);
t_node_months *get_months(const char *key, t_node_months **arr_months);
void free_arr_months(t_node_months **arr_months);

#endif /* _MONTHS_H_ */
