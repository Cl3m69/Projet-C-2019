/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** change_map
*/

#include "../include/my.h"

void change_map(struct_t *stru)
{
    for (int i = stru->stick.linewr, j = stru->stick.colonnes - 2, a = 0; a <
        stru->stick.matcheswr; j--) {
        if (stru->stick.map[i][j] == ' ' || stru->stick.map[i][j] == '*');
        else {
            stru->stick.map[i][j] = ' ';
            stru->stick.nb--;
            a++;
        }
    }
}
