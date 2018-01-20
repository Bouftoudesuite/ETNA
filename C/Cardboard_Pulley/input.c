#include <stdio.h>
char    my_char_upcase(char user_input_case)
{
    int i;

    i = 0;
    if ((user_input_case >= 97) && (user_input_case <= 122))
        user_input_case -= 32;
    return (user_input_case);
}

char 	input()
{
    char user_input_case;
    char user_input_icase;

    user_input_case = getchar();
    user_input_icase = my_char_upcase(user_input_case);
    return (user_input_icase);
}