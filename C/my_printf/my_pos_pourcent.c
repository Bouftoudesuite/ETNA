// Renvoie les positions de toutes les lettres après pourcent
int* my_pos_pourcent(char* str)
{
    int* positions;
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            positions[j] = i;
            j++;
        }
        positions[j] = -1;
        i++;
    }

    return positions;
}
