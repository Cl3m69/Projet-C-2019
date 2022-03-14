/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_key
*/

#include "tetris.h"

int check_max_line(setup_t *setup)
{
    int max = 0;
    int tmp = 0;

    for (; setup->parts[0][tmp] != 0; tmp++);
    for (int i = 0; setup->parts[i] != NULL; i++) {
        for (int j = 0; setup->parts[i][j] != 0; j++, max++);
        if (tmp < max)
            tmp = max;
        max = 0;
    }
    return tmp;
}

void function_press(setup_t *setup, coord_t *coord, int i)
{
    clear();
    for (int i = 0; setup->parts[i] != NULL; i++) {
        for (int j = 0; setup->parts[i][j] != 0; j++)
            setup->map[i + coord->z][j + coord->x + coord->b] = 0;
    }
    if (i == 1)
        coord->b++;
    if (i == 2)
        coord->b--;
    if (i == 3)
        coord->z++;
    if (i == 4) {
        coord->z++;
        coord->tmp++;
    }
}

void key_paus_quit(setup_t *setup, coord_t *coord, int key)
{
    if (my_strcmp(setup->key_pause, "(space)") == 0 && ' ' == key) {
        for (setup->pause = 1; setup->pause == 1;) {
            key = getch();
            if (coord->tmp <= clock() / CLOCKS_PER_SEC)
                coord->tmp++;
            if (' ' == key)
                setup->pause = 0;
        }
    } if (setup->key_pause[0] == key) {
        for (setup->pause = 1; setup->pause == 1;) {
            key = getch();
            if (coord->tmp <= clock() / CLOCKS_PER_SEC)
                coord->tmp++;
            if (setup->key_pause[0] == key)
                setup->pause = 0;
        }
    } if (setup->key_quit[0] == key)
        GAME_OVER;
}

void key_press(setup_t *setup, coord_t *coord, int key, int max)
{
    if (my_strcmp(setup->key_lef, tigetstr("kcub1")) == 0) {
        if (key == KEY_LEFT && coord->x + coord->b > 1 &&
        (check_parts(setup, coord) == 0))
            function_press(setup, coord, 2);
    } if (setup->key_lef[0] == key) {
        if (coord->x + coord->b > 1 && (check_parts(setup, coord) == 0))
            function_press(setup, coord, 2);
    } if (my_strcmp(setup->key_righ, tigetstr("kcuf1")) == 0) {
        if (key == KEY_RIGHT && coord->x + coord->b + max - 1 < coord->x * 2
        && (check_parts2(setup, coord) == 0))
            function_press(setup, coord, 1);
    } if (setup->key_righ[0] == key) {
        if (coord->x + coord->b + max - 1 < coord->x * 2 &&
        (check_parts2(setup, coord) == 0))
            function_press(setup, coord, 1);
    } if (my_strcmp(setup->key_drop, tigetstr("kcud1")) == 0) {
        if (key == KEY_DOWN)
            function_press(setup, coord, 3);
    } if (setup->key_drop[0] == key)
        function_press(setup, coord, 3);
    key_paus_quit(setup, coord, key);
}