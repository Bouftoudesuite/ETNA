#include <stdarg.h>

void my_putchar(char c);
void my_putstr(const char * restrict str);
void my_put_nbr(int n);
int my_strlen(char* str);
int my_nbrlen(int n);

int my_put_no_flag(va_list variables, int compteur, int j)
{
    my_putchar('%');
    compteur++;
    return compteur;
}

int my_put_c(va_list variables, int compteur, int j)
{
    int i;
    char var;

    i = 0;
    var = '\0';
    while (i <= j)
    {
        var = (char) va_arg(variables, int);
        i++;
    }
    my_putchar(var);
    compteur++;
    return compteur;
}

int my_put_d(va_list variables, int compteur, int j)
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
    my_put_nbr(var);
    size = my_nbrlen(var);
    compteur += size;
    return compteur;
}

int my_put_i(va_list variables, int compteur, int j)
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
    my_put_nbr(var);
    size = my_nbrlen(var);
    compteur += size;
    return compteur;
}

int my_put_s(va_list variables, int compteur, int j)
{
    int i;
    char* var;
    int size;

    i = 0;
    var = 0;
    while (i <= j)
    {
        var = va_arg(variables, char*);
        i++;
    }
    my_putstr(var);
    size = my_strlen(var);
    compteur += size;
    return compteur;
}
