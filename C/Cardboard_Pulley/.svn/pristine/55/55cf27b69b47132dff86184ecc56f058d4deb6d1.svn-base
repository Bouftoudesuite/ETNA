/*
** input.c for Cardboard_Pulley in /cygdrive/c/Users/Habi/Documents/ETNA/C/Cardboard_Pulley/etape1
**
** Made by HABI Açal
** Login   <habi_a@etna-alternance.net>
**
** Started on  Sat Jan 20 23:32:37 2018 HABI Açal
** Last update Sat Jan 20 23:33:02 2018 HABI Açal
*/
#include <stdlib.h>
#include <unistd.h>

char		my_char_upcase(char user_input_case)
{
    if ((user_input_case >= 97) && (user_input_case <= 122))
        user_input_case -= 32;
    return (user_input_case);
}


char		readline()
{
    ssize_t	ret;
    char	*buff;

    if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
        return ('\0');
    if ((ret = read(0, buff, 50)) > 1)
    {
        buff[ret - 1] = '\0';
        buff[0] = my_char_upcase(buff[0]);
        return (buff[0]);
    }
    free(buff);
    return ('\0');
}
