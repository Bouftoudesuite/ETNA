#ifndef		_PRINT_H_
# define	_PRINT_H_

# include	<flags.h>

void		print_argv(unsigned int size, const char *path, t_list_flags *list_flags);
void		print_argv_only(const char *path, t_list_flags *list_flags);
void		print_error(const char *path);
void		print_results(char **resultab, unsigned int size, t_list_flags *list_flags, const char *pwd);

#endif		/* _PRINT_H_ */
