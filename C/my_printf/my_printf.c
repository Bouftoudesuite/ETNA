char* my_check_pourcent(char* str, int* positions);
int* my_pos_pourcent(char* str);
char* my_str_replace(char* str, int* positions, char* lettres);
void my_putstr(char* str);

void my_printf(char* str)
{
    int* positions = my_pos_pourcent(str);
    char* lettres = my_check_pourcent(str, positions);
    char* newstr = my_str_replace(str, positions, lettres);
    my_putstr(newstr);
}
