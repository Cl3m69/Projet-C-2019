/*
** EPITECH PROJECT, 2019
** SU_my_printf_2019
** File description:
** my_put_unsigned
*/

#include "../../include/my.h"

int my_put_unsigned(unsigned int nb)
{
    unsigned int i;
    i = nb;

    if (i > 9)
    {
        my_put_unsigned(i / 10);
    }
    my_putchar('0' + i % 10);
    return (0);
}
