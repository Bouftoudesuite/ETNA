int my_printf(const char * restrict str, ...);
void my_put_nbr(int n);

int main(int argc, char const *argv[])
{
    my_printf("Voici une lettre: %c\nVoici une addition: %d + %i = %d\nVoici une chaine de caractere: %s\nVoici un faux pourcentage: 100%%\n", 'A', 2, 3, 2 + 3, "Hello Word!");
    my_put_nbr(my_printf("Voici une lettre: %c\nVoici une addition: %d + %i = %d\nVoici une chaine de caractere: %s\nVoici un faux pourcentage: 100%%\n", 'A', 2, 3, 2 + 3, "Hello Word!"));
    return 0;
}
