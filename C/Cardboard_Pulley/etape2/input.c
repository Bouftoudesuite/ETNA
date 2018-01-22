/*
** input.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
** 
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Sat Jan 20 23:32:37 2018 HABI Açal
** Last update Sat Jan 20 23:33:02 2018 HABI Açal
*/
#include <stdio.h>

char		my_char_upcase(char user_input_case)
{
    if ((user_input_case >= 97) && (user_input_case <= 122))
        user_input_case -= 32;
    return (user_input_case);
}

char		input()
{
    char	user_input_case;
    char	user_input_icase;

    user_input_case = getchar();
    user_input_icase = my_char_upcase(user_input_case);
    return (user_input_icase);
}
