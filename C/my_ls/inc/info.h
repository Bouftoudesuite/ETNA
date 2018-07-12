#ifndef _PRINT_H_
# define _PRINT_H_

#include <flags.h>
#include <sys/stat.h>
#include <sys/types.h>

void print_info(struct stat *buffer, t_list_flags *list_flags);

#endif /* _PRINT_H_ */
