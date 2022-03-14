/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** deleted_lines
*/

#include "tetris.h"

int deleted_lines_true(setup_t *setup, int i)
{
    int e = i - 1;

    if (i == 0)
        return 0;
    for (; e >= 0; ) {
        for (int j = 1; setup->map[e][j] != -1; j++)
            setup->map[i][j] = setup->map[e][j];
        i--;
        e--;
    }
    return 0;
}

int check_lines(setup_t *setup, int i)
{
    for (int j = 1; setup->map[i][j] != -1; j++) {
        if (setup->map[i][j] == 0) {
            return 0;
        }
    }
    if (i == setup->coord.y * 2)
        return 0;
    return 1;
}

void deleted_lines(setup_t *setup)
{
    int check = 0;
    static int l = 0;
    int nb = 0;

    for (int i = 0; setup->map[i] != NULL; i++) {
        check = check_lines(setup, i);
        if (check != 0) {
            deleted_lines_true(setup, i);
            nb++;
        }
        check = 0;
    }
    setup->line += nb;
    setup->score += 200 * nb * nb * setup->level;
    l += 200 * nb * nb * setup->level;
    if (l >= 1000) {
        setup->level++;
        l = 0;
    }
}