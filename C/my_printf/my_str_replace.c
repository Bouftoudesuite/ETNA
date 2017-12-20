int my_strlen(char* str);
void my_putchar(char c);

char* my_str_replace(char* str, int* positions, char* lettres)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int size = my_strlen(str) + 1;
    char newstr[size];

    while (str[i] != '\0')
    {
        if (i == positions[k])
        {
            newstr[j] = 'X';
            i++;
            j++;
            k++;
        }
        else
        {
            newstr[j] = str[i];
            j++;
        }
        i++;
    }
    return newstr;
}