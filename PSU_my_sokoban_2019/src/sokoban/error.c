/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** error
*/

#include "../include/print.h"
#include "../include/sokoban.h"
#include <unistd.h>

void flag_h(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0) {
        my_printf("USAGE\n     ./my_sokoban map\n");
        my_printf("DESCRIPTION\n     map  file representing the warehouse");
        my_printf(" map, containing ‘#’ for walls,\n          ");
        my_printf("‘P’ for the player, ‘X’ for boxes and ‘O’ for storage");
        my_printf("locations.\n");
    }
}

int check_map(map_t *map)
{
    int i = 0;

    map->lines = 0;
    map->colums = 0;
    while (map->test[i] != 0) {
        if (!(map->test[i] == '#' || map->test[i] == 'P' || map->test[i] == '\n'
        || map->test[i] == 'X' || map->test[i] == 'O' || map->test[i] == ' '))
            return 84;
        if (map->test[i + 1] == 0 && map->test[i] != '\n')
            return 84;
        if (map->test[i] == '\n')
            map->lines++;
        i++;
    }
    for (int i = 0, tmp = 0; map->test[i] != 0; i++, tmp = 0) {
        for (; map->test[i] != '\n'; tmp++, i++);
        if (tmp > map->colums)
             map->colums = tmp;
    }
    return 0;
}

int check_error(map_t *map, int ac, char **av)
{
    struct stat size_h;
    error_t error;

    if (ac != 2 || (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)) {
        flag_h(ac, av);
        return 84;
    }
    stat(av[1], &size_h);
    map->sizemap = size_h.st_size;
    map->test = malloc(sizeof(char) * map->sizemap + 1);
    error.fd = open(av[1], O_RDONLY);
    if (error.fd == -1)
        return 84;
    error.df = read(error.fd, map->test, map->sizemap);
    if (error.df == -1)
        return 84;
    map->test[map->sizemap] = 0;
    if (check_map(map) == 84)
        return 84;
    return 0;
}