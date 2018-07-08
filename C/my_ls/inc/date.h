#ifndef _DATE_H_
#define _DATE_H_

#include <flags.h>
#include <months.h>

int strcmp_date(const char *path_one, const char *path_two, const char *pwd, t_node_months **arr_month, t_list_flags *flags);

#endif /* _DATE_H_ */
