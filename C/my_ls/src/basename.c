#include <my.h>
#include <stdlib.h>

static char *get_basename(const char *str)
{
    char *basename;
    unsigned int i;
    unsigned int size_before;

    i = 0;
    size_before = 0;
    if (str == NULL)
        return (NULL);
    while (str[size_before] == '.' || str[size_before] == '/')
        size_before++;
    basename = malloc((my_strlen(str) - size_before + 1) * sizeof(char));
    while (str[size_before])
    {
        basename[i] = str[size_before];
        size_before++;
        i++;
    }
    basename[i] = '\0';
    return (basename);
}

int strcmp_basename(const char *str1, const char *str2)
{
    char ch1;
    char ch2;
    char *s1;
    char *s2;
    unsigned int i;

    i = 0;
    s1 = get_basename(str1);
    s2 = get_basename(str2);
    if (!s1 || !s2)
        return (0);
    while (s1[i] && s2[i] && my_lowcase(s1[i]) == my_lowcase(s2[i]))
        ++i;
    ch1 = s1[i];
    ch2 = s2[i];
    free(s1);
    free(s2);
    return (my_lowcase(ch1) - my_lowcase(ch2));
}
