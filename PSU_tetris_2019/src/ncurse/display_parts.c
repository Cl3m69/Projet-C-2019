/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_parts
*/

#include "tetris.h"

void display_map(setup_t *setup)
{
    for (int i = 0; setup->map[i] != NULL; i++) {
        for (int j = 1; setup->map[i][j] != -1; j++) {
            if (setup->map[i][j] > 0) {
                attron(COLOR_PAIR(setup->map[i][j]));
                mvprintw(3 + i, 57 + j, "*");
            }
        }
    }
}

int display_parts2(setup_t *setup, coord_t *coord, int i, int j)
{
    if (coord->tmp <= (coord->time / CLOCKS_PER_SEC))
        function_press(setup, coord, 4);
    if (setup->parts[i][j] == '*')
        setup->map[i + coord->z][j + coord->x + coord->b] = setup->colorparts;
    if (check_star(setup, coord->z, coord->x) == 84 && coord->z == 0)
        GAME_OVER;
    if (check_star(setup, coord->z, coord->x) == 84) {
        for (; setup->parts[i] != NULL; i++, j = 0) {
            for (; setup->parts[i][j] != 0; j++) {
                if (setup->parts[i][j] == '*')
                    setup->map[i + coord->z][j + coord->x + coord->b] =
                    setup->colorparts;
            }
        }
        return 0;
    }
    return 1;
}

int display_parts(setup_t *setup, coord_t *coord, int a, int key)
{
    int max = check_max_line(setup);

    if (a == -1) {
        coord->z = 0;
        coord->b = 0;
    }
    key_press(setup, coord, key, max);
    coord->time = clock() * setup->level;
    for (int i = 0; setup->parts[i] != NULL; i++) {
        for (int j = 0; setup->parts[i][j] != 0; j++) {
            if (display_parts2(setup, coord, i, j) == 0)
                return 0;
        }
    }
    return 1;
}