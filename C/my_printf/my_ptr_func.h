#ifndef		_MY_PTR_FUNC_H_
#define		_MY_PTR_FUNC_H_

#include <stdarg.h>

int my_put_no_flag(va_list variables, int compteur, int j);
int my_put_c(va_list variables, int compteur, int j);
int my_put_i(va_list variables, int compteur, int j);
int my_put_d(va_list variables, int compteur, int j);
int my_put_s(va_list variables, int compteur, int j);
int my_put_o(va_list variables, int compteur, int j);
int my_put_u(va_list variables, int compteur, int j);
int my_put_x(va_list variables, int compteur, int j);
int my_put_X(va_list variables, int compteur, int j);

int (*ptr_func[9])(va_list, int, int) =
{
    my_put_no_flag,
    my_put_c,
    my_put_s,
    my_put_d,
    my_put_i,
    my_put_o,
    my_put_u,
    my_put_x,
    my_put_X
};

#endif		/* !_MY_PTR_FUNC_H_ */
