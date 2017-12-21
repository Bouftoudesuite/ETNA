void my_printf(char* str, ...);

int main(int argc, char const *argv[])
{
    char lettre_pref = 'D';
    int age = 5;
    my_printf("Bonjour, ma lettre prefere est %c, et jai %d ans.", lettre_pref, age);
    return 0;
}
