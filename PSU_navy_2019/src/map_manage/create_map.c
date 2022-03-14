/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** create_map.c
*/

#include "my.h"
#include "navy.h"

int is_win(map_t *map)
{
    if (map->win == 14) {
        map->game = 0;
        return 1;
    }
    if (map->en_win == 14) {
        map->game = -1;
        return 1;
    }
    return 0;
}

void create_map2(char ***map)
{
    (*map)[2] = malloc(sizeof(char) * 20);
    for (int x = 0, nb = 1, i = 2; i != 10; x++) {
        if (x != 1 && x % 2 != 0 && x != 17)
            (*map)[i][x] = ' ';
        if (x == 0)
            (*map)[i][x] = nb + 48;
        if (x == 1)
            (*map)[i][x] = '|';
        if (x != 1 && x != 0 && x != 17 && x % 2 == 0)
            (*map)[i][x] = '.';
        if (x == 17) {
            (*map)[i][x] = 0;
            x = -1;
            nb++;
            i++;
            (*map)[i] = malloc(sizeof(char) * 20);
        }
    }
}

void create_map(char ***map)
{
    (*map) = malloc(sizeof(char *) * 11);
    (*map)[0] = malloc(sizeof(char) * 18);
    (*map)[0][0] = ' ';
    (*map)[0][1] = '|';
    for (int y = 2, letter = 65; y != 17; y++) {
        if (y % 2 != 0)
            (*map)[0][y] = ' ';
        else {
            (*map)[0][y] = letter;
            letter++;
        }
    }
    (*map)[0][17] = 0;
    (*map)[1] = malloc(sizeof(char) * 20);
    for (int y = 0; y != 17; y++)
        (*map)[1][y] = '-';
    (*map)[1][17] = 0;
    (*map)[1][1] = '+';
    create_map2(map);
}