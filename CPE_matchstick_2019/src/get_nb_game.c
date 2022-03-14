/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** get_nb_game
*/

#include "../include/my.h"

int get_iawin(struct_t *stru)
{
    ia_t *listewin = stru->listewin->premier;
    int check = 0;

    while (listewin->suivant != NULL) {
        for (int i = 1, j = 1; stru->stick.map[i] != NULL; i++, j = 1) {
            for (; stru->stick.map[i][j] != 0; j++) {
                (stru->stick.map[i][j] != listewin->map[i][j]) ?
                check = 84 : 0;
            }
        }
        if (check != 84) {
            stru->stick.matcheswr = listewin->match;
            stru->stick.linewr = listewin->line;
            return 1;
        }
        listewin = listewin->suivant;
        check = 0;
    }
    return check;
}

void get_lineia(struct_t *stru)
{
    int check = 1;

    srand(time(NULL));
    while (check != 0) {
        stru->stick.linewr = 1 + rand() % (stru->stick.line - 2);
        for (int i = 1; stru->stick.map[stru->stick.linewr][i] != '*'; i++) {
            if (stru->stick.map[stru->stick.linewr][i] == '|')
                check = 0;
        }
    }
}

void get_matchia(struct_t *stru)
{
    int check = 1;
    int count = 0;

    srand(time(NULL));
    while (check != 0) {
        stru->stick.matcheswr = 1 + rand() % stru->stick.matches;
        for (int i = 1; stru->stick.map[stru->stick.linewr][i] != '*'; i++) {
            if (stru->stick.map[stru->stick.linewr][i] == '|')
                count++;
        }
        if (count >= stru->stick.matcheswr)
            check = 0;
        count = 0;
    }
}