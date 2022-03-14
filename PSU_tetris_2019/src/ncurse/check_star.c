/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_star
*/

#include "tetris.h"

int check_star2(setup_t *setup, int z, int x, int i)
{
    for (int j = 0; setup->parts[i][j] != 0; j++) {
        if (setup->parts[i + 1] != NULL && my_strlen(setup->parts[i + 1]) < j
        && setup->map[z + i][j + x + setup->coord.b] > 0 &&
        setup->map[z + 1 + i][j + x + setup->coord.b] != 0)
            return 84;
        if (setup->parts[i + 1] != NULL && my_strlen(setup->parts[i + 1]) >= j
        && setup->parts[i + 1][j] != '*' &&
        setup->map[z + i][j + x + setup->coord.b] > 0 &&
        setup->map[z + 1 + i][j + x + setup->coord.b] != 0)
            return 84;
        if (setup->parts[i + 1] == NULL) {
            if (setup->map[z + i][j + x + setup->coord.b] > 0 &&
            setup->map[z + 1 + i][j + x + setup->coord.b] != 0)
                return 84;
        }
    }
    return 0;
}

int check_star(setup_t *setup, int z, int x)
{
    for (int i = 0; setup->parts[i] != NULL; i++) {
        if (check_star2(setup, z, x, i) == 84)
            return 84;
    }
    return 0;
}