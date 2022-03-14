/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_error.c
*/

#include "my.h"
#include "navy.h"

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("²     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid: only for the 2nd player. ");
    my_putstr("pid of the first player.\n");
    my_putstr("     navy_positions: file representing ");
    my_putstr("the positions of the ships.\n");
}

int check_error(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0) {
        print_help();
        return 0;
    }
    if (ac > 3 || ac == 1)
        return 84;
    if (ac == 3) {
        if (my_getnbr(av[1]) == -1)
            return 84;
    }
    return 1;
}