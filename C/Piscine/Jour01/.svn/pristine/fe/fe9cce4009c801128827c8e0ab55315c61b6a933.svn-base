/*
** my_aff_comb.c for  in /home/habi/Piscine1/C/Jour01/my_aff_comb
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Mon Sep 25 23:24:31 2017 HABI Acal
** Last update Mon Sep 25 23:24:37 2017 HABI Acal
*/
void my_putchar(char c);

void test_and_print(char a, char b, char c)
{
    if ((a == 55) && (b == 56) && (c == 57))
    {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
    }
    else
    {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
        my_putchar(',');
        my_putchar(' ');
    }
    c++;
}

void    my_aff_comb()
{
    int a;
    int b;
    int c;

    a = 48;
    b = 49;
    c = 50;
    while(a <= 55)
    {
        b = a + 1;
        while( b <= 56 )
        {
            c = b + 1;
            while( c <= 57 )
            {
                test_and_print(a, b, c);
            }
            b++;
        }
        a++;
    }
    my_putchar('\n');
}
