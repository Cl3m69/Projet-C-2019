/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** init_map
*/

#include "../../include/print.h"
#include "../../include/sokoban.h"

void init_pos(map_t *map, int i, int e, int j)
{
    map->loose = 0;
    map->checko = 0;
    map->checkx = 0;
    if (map->test[i] == 'X')
        map->nbx++;
    if (map->test[i] == 'O')
        map->nbo++;
    if (map->test[i] == 'P') {
        map->px = e;
        map->py = j;
    }
}

void init_tab2(map_t *map)
{
    int i = 0;
    int j = 0;
    int e = 0;

    map->mapxp = malloc(sizeof(char *) * (map->lines + 1));
    while (map->test[i] != 0) {
        map->mapxp[e] = malloc(sizeof(char) * map->colums + 1);
        while (map->test[i] != '\n') {
            if (map->test[i] == 'P' || map->test[i] == 'X')
                map->mapxp[e][j] = map->test[i];
            else
                map->mapxp[e][j] = ' ';
            i++;
            j++;
        }
        map->mapxp[e][j] = 0;
        j = 0;
        i++;
        e++;
    }
    map->mapxp[e] = malloc(sizeof(char) * 1);
    map->mapxp[e][0] = 0;
}

void init_tab(map_t *map)
{
    int j = 0;
    int e = 0;
 
    map->map = malloc(sizeof(char *) * (map->lines + 1));
    for (int i = 0; map->test[i] != 0; i++, e++, j = 0) {
        map->map[e] = malloc(sizeof(char) * map->colums + 1);
        while (map->test[i] != '\n') {
            init_pos(map, i, e, j);
            if (map->test[i] == '#' || map->test[i] == 'O')
                map->map[e][j] = map->test[i];
            else
                map->map[e][j] = ' ';
            i++;
            j++;
        }
        map->map[e][j] = 0;
    }
    map->map[e] = malloc(sizeof(char) * 1);
    map->map[e][0] = 0;
}