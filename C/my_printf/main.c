int my_printf(const char * restrict str, ...);

int main(int argc, char const *argv[])
{
    int nombre_enfant = 3;
    my_printf("Bonjour je suis le meilleur homme sur Terre, jai %d enfants", nombre_enfant);

    return 0;
}
