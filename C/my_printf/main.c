//
// Created by Habi on 04/01/2018.
//

int my_printf(const char *str, ...);

int main()
{
    my_printf("%d + %d = %d, pourcent: %d%%, letter: %c, string: %s", 2, 3, 5, 100, 'a', "hello\n");
    return 0;
}