int my_strlen(char* str);
void my_putchar(char c);

char* my_str_replace(char* str, int* positions, char* lettres)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int size = my_strlen(str) - my_strlen(lettres) + 1;
    char newstr[size];

    while (str[i] != '\0')
    {
        if (i == positions[k])
        {
            newstr[j] = 'X';
            my_putchar('\n');
            i++;
            j++;
            k++;
        }
        else
        {
            //my_putchar(str[i]);
            newstr[j] = str[i];
            j++;
        }
        i++;
        newstr[j] = '\0';
    }
    return newstr;
}