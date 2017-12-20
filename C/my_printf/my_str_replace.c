char* my_str_replace(char* str, int* positions, char* lettres)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char* newstr;

    while (str[i] != -1)
    {
        if (i == positions[k])
            i++;
        else if (i == positions[k] + 1)
        {
            newstr[j] = 'X';
            i++;
            j++;
            k++;
        }
        newstr[j] = str[i];
        i++;
    }
    return newstr;
}
