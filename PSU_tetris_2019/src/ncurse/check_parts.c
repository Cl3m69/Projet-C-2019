/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_parts
*/

#include "tetris.h"

int check_parts_cut2(setup_t *setup, coord_t *coord, int i, int j)
{
    if (setup->map[i + coord->z][j + coord->x + coord->b + 1] != 0)
        return 84;
    return 0;
}

int check_parts2(setup_t *setup, coord_t *coord)
{
    int a = 0;
    int e = 0;
    int c = 0;

    for (int i = 0; setup->parts[i] != NULL; i++, a = 0, e = 0) {
        for (int z = 0; setup->parts[i][z] != 0; z++) {
            if (setup->parts[i][z] == '*')
                a++;
        }
        for (int j = 0; setup->parts[i][j] != 0; j++) {
            if (setup->parts[i][j] == '*')
                e++;
            if (setup->parts[i][j] == '*' && a == e)
                c = check_parts_cut2(setup, coord, i, j);
            if (c == 84)
                return 84;
        }
    }
    return 0;
}

int check_parts_cut(setup_t *setup, coord_t *coord, int i, int j)
{
    if (setup->map[i + coord->z][j + coord->x + coord->b - 1] != 0)
        return 84;
    return 0;
}

int check_parts(setup_t *setup, coord_t *coord)
{
    int a = 0;
    int c = 0;

    for (int i = 0; setup->parts[i] != NULL; i++) {
        for (int j = 0; setup->parts[i][j] != 0; j++) {
            if (setup->parts[i][j] == '*' && a == 0) {
                c = check_parts_cut(setup, coord, i, j);
                a++;
            }
            if (c == 84)
                return 84;
        }
        a = 0;
    }
    return 0;
}
