/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** putstr
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        write(1, &str[i], 1);
        i++;
    }
}
