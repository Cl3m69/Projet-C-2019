/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** error
*/

#include "../include/my.h"

int check_error(char **av, struct_t *stru)
{
    int nb = my_getnbr(av[1]);
    int nb2 = my_getnbr(av[2]);

    if (nb < 2 || nb > 99)
        return 84;
    if (nb2 < 1)
        return 84;
    stru->stick.line = nb + 2;
    stru->stick.matches = nb2;
    return 0;
}