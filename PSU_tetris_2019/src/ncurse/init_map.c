/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_map
*/

#include "tetris.h"

void init_map(setup_t *setup)
{
    int y = (check_x(setup->size));
    int x = (check_y(setup->size));
    int a = 0;

    setup->map = malloc(sizeof(int *) * (y + 3));
    for (; a < y; a++) {
        setup->map[a] = malloc(sizeof(int) * (x + 3));
        for (int z = 1; z <= x; z++) {
            setup->map[a][0] = -1;
            setup->map[a][z] = 0;
            setup->map[a][x+1] = -1;
        }
    }
    setup->map[a] = malloc(sizeof(int) * (x + 3));
    for (int b = 0; b <= x; b++)
        setup->map[a][b] = -1;
    a++;
    setup->map[a] = NULL;
}