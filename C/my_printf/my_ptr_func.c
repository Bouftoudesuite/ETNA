#include "my_printf.h"

int	my_ptr_func(va_list variables, int count, int arg_select,
		    char letter)
{
    int	function_to_call;
    int	(*ptr_func[9])(va_list, int, int);

    ptr_func[0] = my_put_no_flag;
    ptr_func[1] = my_put_c;
    ptr_func[2] = my_put_s;
    ptr_func[3] = my_put_d;
    ptr_func[4] = my_put_i;
    ptr_func[5] = my_put_o;
    ptr_func[6] = my_put_u;
    ptr_func[7] = my_put_x;
    ptr_func[8] = my_put_X;
    function_to_call = my_convert_letter_into_nb(letter);
    count = ptr_func[function_to_call]
      (variables, count, arg_select);
    return (count);
}
