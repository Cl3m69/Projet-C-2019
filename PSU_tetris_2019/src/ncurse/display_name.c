/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_name
*/

#include "tetris.h"

void my_rectangle(int x1, int x2, int y1, int y2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void display_r(void)
{
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    my_rectangle(37, 39, 2, 4);
    my_rectangle(31, 37, 2, 3);
    my_rectangle(34, 36, 4, 5);
    my_rectangle(37, 39, 5, 7);
    my_rectangle(31, 33, 3, 7);
}

void display_e_i_s(int i)
{
    if (i == 2) {
        attron(COLOR_PAIR(i));
        my_rectangle(12, 14, 2, 7);
        my_rectangle(14, 19, 2, 3);
        my_rectangle(14, 18, 4, 5);
        my_rectangle(14, 19, 6, 7);
    }
    else if (i == 4) {
        attron(COLOR_PAIR(4));
        my_rectangle(41, 43, 2, 7);
    }
    else {
        attron(COLOR_PAIR(5));
        my_rectangle(47, 52, 2, 3);
        my_rectangle(45, 47, 2, 5);
        my_rectangle(45, 50, 6, 7);
        my_rectangle(47, 52, 4, 5);
        my_rectangle(50, 52, 5, 7);
    }
}

void display_t(int i)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    if (i == 1) {
        my_rectangle(2, 10, 2, 3);
        my_rectangle(5, 7, 3, 7);
    }
    else if (i == 2) {
        my_rectangle(21, 29, 2, 3);
        my_rectangle(24, 26, 3, 7);
    }
}

void display_setup(setup_t *setup, clock_t chrono)
{
    start_color();
    chrono = clock();
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_GREEN, COLOR_BLACK);
    display_t(1);
    display_e_i_s(2);
    display_t(2);
    display_r();
    display_e_i_s(4);
    display_e_i_s(5);
    display_score(setup, chrono);
    display_win(setup);
    display_next(setup);
}