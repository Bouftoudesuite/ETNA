#ifndef _TOLS_H_
#define _TOLS_H_

#include <params.h>
#include <results.h>

void push_params_to_tols(char **tols, t_list_params *list);
void push_results_to_resultab(char **tols, t_list_results *list);
void free_tab(char **tols, unsigned int size);

#endif /* _TOLS_H_ */
