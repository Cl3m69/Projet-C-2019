/*
** EPITECH PROJECT, 2019
** convert_str.c
** File description:
** covert
*/

#include "../../../include/my.h"

int len_nbr(unsigned int nb)
{
    int i = 1;

    while (nb / 10 != 0) {
        nb = nb / 10;
        i++;
    }
    return i;
}

char *my_hex(int i, unsigned int nb, char *base, char c)
{
    char *str = malloc(sizeof(char) * len_nbr(nb) + 2);

    if (nb != 0 && c == '#' && base[10] == 'A')
        my_putstr("0X");
    if (nb != 0 && c == '#' && base[10] == 'a')
        my_putstr("0x");
    if (nb < 16) {
        str[i] = base[nb];
        i++;
    }
    while (nb / 16 != 0) {
        str[i] = base[nb % 16];
        nb = nb / 16;
        i++;
        if (nb / 16 == 0) {
            str[i] = base[nb % 16];
            i++;
        }
    }
    str[i] = 0;
    return (my_revstr(str));
}

char *my_octale_base(unsigned int nb, char c)
{
    int i = 0;
    char *str = NULL;

    if (nb != 0 && c == '#')
        my_putchar('0');
    str = malloc(sizeof(char) * len_nbr(nb) + 3);
    if (nb < 8) {
        str[i] = nb + 48;
        i++;
    }
    while (nb / 8 != 0) {
        str[i] = (nb % 8 + 48);
        nb = nb / 8;
        i++;
        if (nb / 8 == 0) {
            str[i] = (nb % 8 + 48);
            i++;
        }
    }
    str[i] = 0;
    return (my_revstr(str));
}

char *my_binary_base(unsigned int nb)
{
    int i = 0;
    char *str = NULL;

    str = malloc(sizeof(char) * len_nbr(nb) * 5);
    while (nb / 2 != 0) {
        str[i] = (nb % 2 + 48);
        nb = nb / 2;
        i++;
    }
    if (nb == 0)
        str[i] = '0';
    else
        str[i] = '1';
    str[i + 1] = 0;
    return (my_revstr(str));
}
