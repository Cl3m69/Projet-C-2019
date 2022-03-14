/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "include/sokoban.h"

int main(int ac, char **av)
{
    map_t map;
    int i = 0;

    map.nbx = 0;
    map.nbo = 0;
    if (check_error(&map, ac, av) == 84)
        return 84;
    init_tab(&map);
    init_tab2(&map);
    i = sokoban(&map);
    if (i == 1)
        return 1;
    return 0;
}