#include <stdarg.h>

void my_put_un_nbr(unsigned int n);
void my_put_nbr_base(int n, char* base);
int my_nbrlen(int n);

int my_put_o(va_list variables, int compteur, int j)
{
    int i;
    int var;
    int size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr_base(var, "01234567");
    size = my_nbrlen(var);
    compteur += size;
    return compteur;
}

int my_put_u(va_list variables, int compteur, int j)
{
    int i;
    int var;
    int size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, unsigned int);
        i++;
    }
    my_put_un_nbr(var);
    size = my_nbrlen(var);
    compteur += size;
    return compteur;
}

int my_put_x(va_list variables, int compteur, int j)
{
    int i;
    int var;
    int size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr_base(var, "0123456789ABCDEF");
    size = my_nbrlen(var);
    compteur += size;
    return compteur;
}

int my_put_X(va_list variables, int compteur, int j)
{
    int i;
    int var;
    int size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, int);
        i++;
    }
    my_put_nbr_base(var, "0123456789ABCDEF");
    size = my_nbrlen(var);
    compteur += size;
    return compteur;
}