#ifndef _SORT_H_
#define _SORT_H_

void sort_tols_by_type(char **tab, unsigned int size, t_list_flags *list_flags);
void sort_tols_by_alpha(char **tab, unsigned int size, t_list_flags *list_flags);
void sort_tols_by_alpha_rev(char **tab, unsigned int size, t_list_flags *list_flags);
void sort_tols_by_date(char **tab, unsigned int size, t_list_flags *list_flags, t_node_months **list_months, const char *pwd);
void sort_tols_by_date_rev(char **tab, unsigned int size, t_list_flags *list_flags, t_node_months **arr_months, const char *pwd);
void sort_results_by_date(char **tab, unsigned int size, t_list_flags *list_flags, t_node_months **list_months, const char *pwd);

#endif /* _SORT_H_ */
