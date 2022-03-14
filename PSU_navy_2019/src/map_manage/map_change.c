/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** map_change
*/

#include "navy.h"
#include "my.h"

void change_map(map_t *map, int a)
{
    int y = attack[0];
    int x = attack[1];

    if (a == 0 && map->map[x][y] != 'x')
        map->map[x][y] = 'o';
    if (a == 1) {
        if (map->map[x][y] != 'x')
            map->en_win++;
        map->map[x][y] = 'x';
    }
}

void change_en_map(map_t *map, char *buf)
{
    int y = buf[0] - (63 - (1 * (buf[0] - 65)));
    int x = buf[1] - 47;

    if (attack[3] == 0 &&  map->en_map[x][y] != 'x')
        map->en_map[x][y] = 'o';
    if (attack[3] == 1) {
        if (map->en_map[x][y] != 'x')
            map->win++;
        map->en_map[x][y] = 'x';
    }
}