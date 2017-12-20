/*
** my_aff_chiffre.c for  in /home/habi/Piscine1/C/Jour01/my_aff_chiffre
** 
** Made by HABI Acal
** Login   <habi_a@etna-alternance.net>
** 
** Started on  Mon Sep 25 16:10:57 2017 HABI Acal
** Last update Mon Sep 25 16:10:59 2017 HABI Acal
*/
void     my_putchar(char c);

void     my_aff_chiffre(void)
{
    int  decimal;

    decimal = 48;
    while (decimal <= 57)
    {
        my_putchar(decimal);
        decimal++;
    }
}
