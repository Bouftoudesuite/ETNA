void        my_putchar(char c);

void        my_putstr(const char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
}
