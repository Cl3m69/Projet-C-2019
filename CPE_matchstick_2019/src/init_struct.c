/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** init_struct
*/

#include "../include/my.h"

void init_map(struct_t *stru)
{
    stru->stick.map = malloc(sizeof(char *) * (stru->stick.line + 1));
    for (int i = 0, j = 0; i < stru->stick.line;
    stru->stick.map[i][j] = 0, j = 0, i++) {
        stru->stick.map[i] = malloc(sizeof(char) * (stru->stick.colonnes + 1));
        for (; j < stru->stick.colonnes; j++) {
            if (i == 0 || i == stru->stick.line - 1)
                stru->stick.map[i][j] = '*';
            else {
                stru->stick.map[i][0] = '*';
                stru->stick.map[i][j] = ' ';
                stru->stick.map[i][stru->stick.colonnes - 1] = '*';
            }
        }
        stru->stick.map[i][j] = 0;
    }
    stru->stick.map[stru->stick.line] = NULL;
}

void init_struct2(struct_t *stru)
{
    int a = 0;

    stru->stick.nb = 0;
    stru->stick.loose = 0;
    for (int i = stru->stick.line - 2, j = 1; i > 0; a++, i--, j = 1 + a) {
        for (; j < stru->stick.colonnes - 1 - a; j++) {
            stru->stick.map[i][j] = '|';
            stru->stick.nb++;
        }
    }
}

void init_struct(struct_t *stru)
{
    stru->stick.game = 0;
    stru->stick.linewr = 0;
    stru->stick.matcheswr = 0;
    stru->stick.nb = 0;
    stru->stick.colonnes = 5 + (stru->stick.line - 2 - 2) * 2;
    init_map(stru);
    init_struct2(stru);
}