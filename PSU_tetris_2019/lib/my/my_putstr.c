/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** putstr
*/

#include "../../include/my.h"

void my_putstr_s(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] < 32 || str[i] == 127) {
            write(1, "\\", 1);
            if (str[i] < 10)
                write(1, "00", 2);
            else if (str[i] > 9 && str[i] < 32)
                write(1, "0", 1);
            my_putstr(my_octale_base(str[i], str[i]));
            i++;
        }
        write(1, &str[i], 1);
        i++;
    }
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        write(1, &str[i], 1);
        i++;
    }
}
