/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** window
*/

#include <ncurses.h>
#include "../../include/sokoban.h"

void display_map(map_t *map)
{
    for (int i = 0; map->map[i] != 0; i++) {
        mvprintw(i, 0, map->map[i]);
        printw("\n");
    }
    for (int i = 0, j = 0; map->mapxp[i][0] != 0; i++, j = 0) {
        for (; map->mapxp[i][j] != 0; j++) {
            if (map->mapxp[i][j] == 'X')
                mvprintw(i, j, "X");
            if (map->mapxp[i][j] == 'P')
                mvprintw(i, j, "P");
        }
    }
}

void check_move(map_t *map)
{
    int key = 0;

    key = getch();
    switch (key) {
    case (KEY_UP):
        key_up(map);
        break;
    case (KEY_DOWN):
        key_down(map);
        break;
    case (KEY_RIGHT):
        key_right(map);
        break;
    case (KEY_LEFT):
        key_left(map);
        break;
    case (' '):
        init_tab(map);
        init_tab2(map);
        break;
    }
}

int sokoban(map_t *map)
{
    int i = 2;

    initscr();
    keypad(stdscr, TRUE);
    display_map(map);
    while (i == 2) {
        curs_set(0);
        check_move(map);
        display_map(map);
        refresh();
        if (map->checko == map->nbo)
            i = 0;
        else if (check_lose(map) == 1)
            i = 1;
    }
    endwin();
    return i;
}
