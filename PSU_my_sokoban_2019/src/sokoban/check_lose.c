/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check_lose
*/

#include "../../include/sokoban.h"

void move_xcut(map_t *map, int i, int j, int *e)
{
    if ((map->map[i+1][j] == '#' || map->mapxp[i+1][j] == 'X') &&
    (map->map[i][j+1] == '#' || map->mapxp[i][j+1] == 'X'))
        *e += 1;
    else if ((map->map[i+1][j] == '#' || map->mapxp[i+1][j] == 'X') &&
    (map->map[i][j-1] == '#' || map->mapxp[i][j-1] == 'X'))
        *e +=1;
}

void move_x(map_t *map, int i, int j, int *e)
{
    if ((map->map[i-1][j] == '#' || map->mapxp[i-1][j] == 'X') &&
    (map->map[i][j-1] == '#' || map->mapxp[i][j-1] == 'X'))
        *e += 1;
    else if ((map->map[i-1][j] == '#' || map->mapxp[i-1][j] == 'X') &&
    (map->map[i][j+1] == '#' || map->mapxp[i][j+1] == 'X'))
        *e += 1;
    else
        move_xcut(map, i, j, e);
}

int check_lose(map_t *map)
{
    int e = 0;

    for (int i = 0, j = 0; map->mapxp[i][0] != 0; i++, j = 0) {
        for (; map->mapxp[i][j] != 0; j++) {
            if (map->mapxp[i][j] == 'X')
                move_x(map, i, j, &e);
        }
    }
    if (e == map->nbx)
        return 1;
    return 0;
}
