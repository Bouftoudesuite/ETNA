#ifndef		_TOLS_H_
# define	_TOLS_H_

# include	<flags.h>
# include	<params.h>
# include	<results.h>

void		push_params_to_tols(char **tols, t_list_params *list);
void		push_results_to_resultab(char **tols, t_list_results *list, t_list_flags *list_f);
unsigned int	push_resultab_to_newtols(char **new_tols, char **resultab, unsigned int result_size, const char *pwd);
void		free_tab(char **tols, unsigned int size);

#endif		/* _TOLS_H_ */
