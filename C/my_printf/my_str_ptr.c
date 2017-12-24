#include <stdarg.h>

void my_putchar(char c);
void my_putstr(const char * restrict str);
void my_put_nbr(int n);
void my_put_un_nbr(unsigned int n);
void my_put_nbr_base(int n, char* base);
int my_strlen(char* str);
int my_str_ptr_bis(int compteur, char lettre, va_list variables);

int my_str_ptr(int compteur, char lettre, va_list variables)
{
    char* str;

    if (lettre == 'c')
    {
        my_putchar(va_arg(variables, char));
        compteur++;
    }
    else if (lettre == 'd' || lettre == 'i')
    {
        my_put_nbr(va_arg(variables, int));
        compteur++;
    }
    else if (lettre == 's')
    {
        str = va_arg(variables, char*);
        my_putstr(str);
        compteur += my_strlen(str);
    }
    else
        compteur = my_str_ptr_bis(compteur, lettre, variables);
    return compteur;
}

int my_str_ptr_bis(int compteur, char lettre, va_list variables)
{
    if (lettre == 'o')
    {
        my_put_nbr_base(va_arg(variables, int), "01234567");
        compteur++;
    }
    else if (lettre == 'u')
    {
        my_put_un_nbr(va_arg(variables, unsigned int));
        compteur++;
    }
    else if (lettre == 'x' || lettre == 'X')
    {
        my_put_nbr_base(va_arg(variables, int), "0123456789ABCDEF");
        compteur++;
    }
    else
        my_putstr("Parametre non reconnu \n");
    return compteur;
}