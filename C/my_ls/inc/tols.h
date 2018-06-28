#ifndef _TOLS_H_
#define _TOLS_H_

#include <params.h>

void push_params_to_tols(char **tols, t_list_params *list);
void free_tols(char **tols, unsigned int size);

#endif //_TOLS_H_
