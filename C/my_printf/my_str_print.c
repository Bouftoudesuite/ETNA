int my_strlen(char* str);
void my_putchar(char c);
void my_putstr(char* str);

void my_str_print(char* str, int* positions, char* lettres)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0')
    {
        if (i == positions[k])
        {
            if (lettres[k] == 'c')
                my_putchar('X');
            else if (lettres[k] == 'd')
                my_putchar('5');
            i++;
            j++;
            k++;
        }
        else
        {
            my_putchar(str[i]);
            j++;
        }
        i++;
    }
}