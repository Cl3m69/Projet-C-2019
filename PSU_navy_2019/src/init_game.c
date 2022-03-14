/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** init_game
*/

#include "my.h"
#include "navy.h"

int init_game(map_t *map, int ac, char **av)
{
    int i = 0;

    if (ac == 2) {
        if ((i = first_user(map, av[1])) != 0)
            return i;
    }
    else {
        if ((i = second_usr(map, av[1], av[2])) != 0)
            return i;
    }
    return 0;
}