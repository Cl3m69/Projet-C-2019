/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** player_move
*/

#include "../../include/sokoban.h"

void key_left(map_t *map)
{
    if (map->mapxp[map->px][map->py - 1] == 'X' &&
    (map->map[map->px][map->py - 2] != '#' &&
    map->mapxp[map->px][map->py - 2] != 'X')) {
        if (map->mapxp[map->px][map->py - 1] == 'X' &&
        map->map[map->px][map->py - 2] == 'O')
            map->checko++;
        else if (map->mapxp[map->px][map->py - 1] == 'X' &&
        map->map[map->px][map->py - 1] == 'O')
            map->checko--;
        map->mapxp[map->px][map->py] = ' ';
        map->py -= 1;
        map->mapxp[map->px][map->py] = 'P';
        map->mapxp[map->px][map->py - 1] = 'X';
    }
    else if (map->map[map->px][map->py - 1] != '#' &&
    map->mapxp[map->px][map->py - 1] != 'X') {
        map->mapxp[map->px][map->py] = ' ';
        map->py -= 1;
        map->mapxp[map->px][map->py] = 'P';
    }
}

void key_right(map_t *map)
{
    if (map->mapxp[map->px][map->py + 1] == 'X' &&
    (map->map[map->px][map->py + 2] != '#' &&
    map->mapxp[map->px][map->py + 2] != 'X')) {
        if (map->mapxp[map->px][map->py + 1] == 'X' &&
        map->map[map->px][map->py + 2] == 'O')
            map->checko++;
        else if (map->mapxp[map->px][map->py + 1] == 'X' &&
        map->map[map->px][map->py + 1] == 'O')
            map->checko--;
        map->mapxp[map->px][map->py] = ' ';
        map->py += 1;
        map->mapxp[map->px][map->py] = 'P';
        map->mapxp[map->px][map->py + 1] = 'X';
    }
    else if (map->map[map->px][map->py + 1] != '#' &&
    map->mapxp[map->px][map->py + 1] != 'X') {
        map->mapxp[map->px][map->py] = ' ';
        map->py += 1;
        map->mapxp[map->px][map->py] = 'P';
    }
}

void key_down(map_t *map)
{
    if (map->mapxp[map->px + 1][map->py] == 'X' &&
    (map->map[map->px + 2][map->py] != '#' &&
    map->mapxp[map->px + 2][map->py] != 'X')) {
        if (map->mapxp[map->px + 1][map->py] == 'X' &&
        map->map[map->px + 2][map->py] == 'O')
            map->checko++;
        else if (map->mapxp[map->px + 1][map->py] == 'X' &&
        map->map[map->px + 1][map->py] == 'O')
            map->checko--;
        map->mapxp[map->px][map->py] = ' ';
        map->px += 1;
        map->mapxp[map->px][map->py] = 'P';
        map->mapxp[map->px + 1][map->py] = 'X';
    }
    else if (map->map[map->px + 1][map->py] != '#' &&
    map->mapxp[map->px + 1][map->py] != 'X') {
        map->mapxp[map->px][map->py] = ' ';
        map->px += 1;
        map->mapxp[map->px][map->py] = 'P';
    }
}

void key_up(map_t *map)
{
    if (map->mapxp[map->px - 1][map->py] == 'X' &&
    (map->map[map->px - 2][map->py] != '#' &&
    map->mapxp[map->px - 2][map->py] != 'X')) {
        if (map->mapxp[map->px - 1][map->py] == 'X' &&
        map->map[map->px - 2][map->py] == 'O')
            map->checko++;
        else if (map->mapxp[map->px - 1][map->py] == 'X' &&
        map->map[map->px - 1][map->py] == 'O')
            map->checko--;
        map->mapxp[map->px][map->py] = ' ';
        map->px -= 1;
        map->mapxp[map->px][map->py] = 'P';
        map->mapxp[map->px - 1][map->py] = 'X';
    }
    else if (map->map[map->px - 1][map->py] != '#' &&
    map->mapxp[map->px - 1][map->py] != 'X') {
        map->mapxp[map->px][map->py] = ' ';
        map->px -= 1;
        map->mapxp[map->px][map->py] = 'P';
    }
}
