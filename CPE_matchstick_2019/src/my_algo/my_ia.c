/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_ia
*/

#include "../../include/my.h"

void norme(struct_t *stru)
{
    for (int e = 1, j = 1, c = 0; stru->stick.map[e] != NULL; e++, j = 1) {
        for (; stru->stick.map[e][j] != 0; j++, c = 0)
            (stru->stick.map[e][j] == '|') ? c++ : 0;
        if (c == 2) {
            stru->stick.matcheswr = 2;
            stru->stick.linewr = e;
        }
    }
}

void check_win(struct_t *stru, int i)
{
    for (int j = 0; stru->stick.map[stru->stick.linewr][j] != 0; j++) {
        if (stru->stick.map[stru->stick.linewr][j] == '|')
            i++;
    }
    if (i == stru->stick.nb && i <= stru->stick.matches && i != 1)
        stru->stick.matcheswr = i - 1;
    if (i == stru->stick.nb - 1 && i <= stru->stick.matches && i != 1)
        stru->stick.matcheswr = i;
    if (i == stru->stick.nb - 2) {
        norme(stru);
    }
}

void my_ia1(struct_t *stru)
{
    int i = 0;

    if (get_matchiawin(stru) == 1);
    else {
        get_lineia2(stru);
        get_matchia2(stru);
    }
    check_win(stru, i);
    add_elementliste1(stru);
    change_map_ia(stru);
    if (stru->stick.nb == 0) {
        stru->stick.game = 1;
        if (stru->stick.matcheswr > 1)
            stru->liste2->premier = stru->liste2->premier->suivant;
    }
}

void my_ia2(struct_t *stru)
{
    int i = 0;

    if (get_matchiawin(stru) == 1);
    else {
        get_lineia2(stru);
        get_matchia2(stru);
    }
    check_win(stru, i);
    add_elementliste2(stru);
    change_map_ia(stru);
    if (stru->stick.nb == 0) {
        stru->stick.game = 2;
        if (stru->stick.matcheswr > 1)
            stru->liste1->premier = stru->liste1->premier->suivant;
    }
}