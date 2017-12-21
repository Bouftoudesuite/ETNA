int my_strlen(const char * restrict str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
