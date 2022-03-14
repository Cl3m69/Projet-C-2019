/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** rotate_parts
*/

#include "tetris.h"

int check_new(setup_t *setup, char **new)
{
    for (int i = 0; new[i] != NULL; i++) {
        for (int j = 0; new[i][j] != 0; j++) {
            if (setup->map[setup->coord.z + i]
            [j + setup->coord.x + setup->coord.b] != 0)
                return 84;
        }
    }
    return 0;
}

char **rotate_cut(setup_t *setup, int line, int cols)
{
    char **new = NULL;
    int a = 0;
    int b = 0;

    new = malloc(sizeof(char *) * (cols + 1));
    for (int i = 0; i < cols; i++) {
        new[a] = malloc(sizeof(char) * line + 1);
        for (int j = 0; setup->parts[j] != NULL; j++) {
            new[a][b] = setup->parts[j][i];
            b++;
        }
        new[a][b] = 0;
        b = 0;
        a++;
    }
    new[a] = NULL;
    clear();
    return new;
}

void rotate_parts(setup_t *setup)
{
    char **new = NULL;
    int line = 0;
    int cols = 0;
    int tmp = 0;

    for (; setup->parts[0][tmp] != 0; tmp++);
    for (; setup->parts[line] != NULL; line++) {
        for (; setup->parts[line][cols] != 0; cols++);
        if (tmp < cols)
            tmp = cols;
        cols = 0;
    }
    cols = tmp;
    new = rotate_cut(setup, line, cols);
    for (int i = 0; setup->parts[i] != NULL; i++) {
        for (int j = 0; setup->parts[i][j] != 0; j++)
            setup->map[i + setup->coord.z][
            j + setup->coord.x + setup->coord.b] = 0;
    }
    if (check_new(setup, new) == 0)
        setup->parts = new;
}