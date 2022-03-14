/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** get_nb_ia
*/

#include "../../include/my.h"

void get_lineia2(struct_t *stru)
{
    int check = 1;

    while (check != 0) {
        stru->stick.linewr = 1 + rand() % (stru->stick.line - 2);
        for (int i = 1; stru->stick.map[stru->stick.linewr][i] != '*'; i++) {
            if (stru->stick.map[stru->stick.linewr][i] == '|')
                check = 0;
        }
    }
}

void get_matchia2(struct_t *stru)
{
    int check = 1;
    int count = 0;

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