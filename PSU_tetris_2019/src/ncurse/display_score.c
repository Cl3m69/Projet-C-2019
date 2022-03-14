/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_score
*/

#include "tetris.h"

int display_next(setup_t *setup)
{
    int x = (check_y(setup->size));

    if (my_strcmp(setup->next, "Yes") != 0)
        return 0;
    for (int i = 0; setup->partsnext[i] != NULL; i++) {
        for (int j = 0; setup->partsnext[i][j] != 0; j++) {
            if (setup->partsnext[i][j] == '*') {
                attron(COLOR_PAIR(setup->colorpartsnext));
                mvprintw(3 + i, 57 + j + x + 5, "*");
            }
        }
    }
    return 0;
}

int check_y(char *str)
{
    int check = 0;
    int x = 0;
    int i = 0;
    char *nb = NULL;

    for (; str[i] != '*'; i++, check++);
    for (; str[check] != 0; check++);
    nb = malloc(sizeof(char) * check + 1);
    i++;
    for (; str[i] != 0; i++, x++) {
        nb[x] = str[i];
    }
    nb[x] = 0;
    x = my_getnbr(nb);
    free(nb);
    return x;
}

int check_x(char *str)
{
    int i = 0;
    int x = 0;
    char *nb = NULL;

    for (; str[i] != '*'; i++);
    nb = malloc(i + 1);
    for (int a = 0; str[a] != '*'; a++, x++)
        nb[x] = str[a];
    nb[x] = 0;
    x = my_getnbr(nb);
    free(nb);
    return x;
}

void display_win(setup_t *setup)
{
    int x = (check_x(setup->size));
    int y = (check_y(setup->size));

    attron(COLOR_PAIR(7));
    my_rectangle(55 + 2, 55 + y + 2 + 1, 2, 2 + x + 1);
    attron(COLOR_PAIR(7));
    my_rectangle(55 + y + 4, 55 + y + 4 + 10, 2, 2 + 5);
}

void display_score(setup_t *setup, clock_t chrono)
{
    int minute = chrono / CLOCKS_PER_SEC / 60;
    int seconde = chrono / CLOCKS_PER_SEC % 60;

    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(7));
    my_rectangle(14, 42, 10, 22);
    mvprintw(12, 17, "High Score :");
    mvprintw(12, 40 - my_strlen(my_itoa(setup->high)), my_itoa(setup->high));
    mvprintw(13, 17, "Score :");
    mvprintw(13, 40 - my_strlen(my_itoa(setup->score)), my_itoa(setup->score));
    mvprintw(16, 17, "Lines :");
    mvprintw(16, 40 - my_strlen(my_itoa(setup->line)), my_itoa(setup->line));
    mvprintw(17, 17, "Level :");
    mvprintw(17, 40 - my_strlen(my_itoa(setup->level)), my_itoa(setup->level));
    mvprintw(20, 17, "Timer :");
    mvprintw(20, 36, "%.2d", minute);
    mvprintw(20, 38, ":");
    mvprintw(20, 39, "%.2d", seconde % 60);
}