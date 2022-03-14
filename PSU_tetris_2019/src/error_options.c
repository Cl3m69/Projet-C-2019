/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** error_options.c
*/

#include "tetris.h"

int check_if_map_size_is_good(char *opt)
{
    int i = 0;
    char *x = "";
    char *y = "";

    for (; opt[i] != '='; i++);
    i++;
    for (; opt[i] >= 48 && opt[i] <= 57; i++)
        x = my_charcat(x, opt[i]);
    if (opt[i] != ',')
        return 84;
    i++;
    for (; opt[i] >= 48 && opt[i] <= 57; i++)
        y = my_charcat(y, opt[i]);
    if (my_getnbr(x) <= 0)
        return 84;
    if (my_getnbr(y) <= 0)
        return 84;
    return 0;
}

int check_if_level_is_good(char *opt)
{
    int i = 0;
    char *nb = "";

    for (; opt[i] != '='; i++);
    i++;
    for (; opt[i] >= 48 && opt[i] <= 57; i++)
        nb = my_charcat(nb, opt[i]);
    if (my_getnbr(nb) <= 0)
        return 84;
    return 0;
}

int error_long_options(char **av)
{
    int i = 0;

    for (; av[i] != 0; i++) {
        if (my_strncmp("--level=", av[i], 8) == 0)
            return (check_if_level_is_good(av[i]));
        if (my_strncmp("--map-size=", av[i], 11) == 0)
            return (check_if_map_size_is_good(av[i]));
    }
    return 0;
}

int useless_options(char **av)
{
    int i = 1;

    for (; av[i] != 0; i++) {
        if (av[i][0] != '-') {
            if ((my_strcmp(av[i - 1], "-L") != 0 &&
                my_strcmp(av[i - 1], "-l") != 0 &&
                my_strcmp(av[i - 1], "-r") != 0 &&
                my_strcmp(av[i - 1], "-t") != 0 &&
                my_strcmp(av[i - 1], "-d") != 0 &&
                my_strcmp(av[i - 1], "-q") != 0 &&
                my_strcmp(av[i - 1], "-p") != 0))
                return 84;
        }
    }
    return 0;
}

int error_options(char **av)
{
    int i = 0;

    for (; av[i] != 0; i++) {
        if (my_strcmp("-L", av[i]) == 0) {
            if (my_getnbr(av[i + 1]) <= 0)
                return 84;
        }
    }
    return 0;
}