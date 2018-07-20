#ifndef		_CHECK_H_
# define	_CHECK_H_

# include	<my.h>

t_bool		is_dir(const char *path);
t_bool		is_file(const char *path);
t_bool		is_same_type(const char *path_one, const char *path_two);
t_bool		path_exist(const char *path);


#endif		/* _CHECK_H_ */
