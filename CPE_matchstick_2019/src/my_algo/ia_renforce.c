/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ia_renforce
*/

#include "../../include/my.h"

void deleted_liste(struct_t *stru)
{
    while (stru->liste1->premier->suivant != NULL) {
        ia_t *deleted = stru->liste1->premier;
        stru->liste1->premier = stru->liste1->premier->suivant;
        free(deleted);
    }
    while (stru->liste2->premier->suivant != NULL) {
        ia_t *deleted = stru->liste2->premier;
        stru->liste2->premier = stru->liste2->premier->suivant;
        free(deleted);
    }
}

void play_ia(struct_t *stru)
{
    for (int i = 0, play = 0; i < (1000 - stru->stick.line * 100); i++) {
        while (stru->stick.game == 0) {
            if (play % 2 == 0)
                my_ia1(stru);
            else
                my_ia2(stru);
            play++;
        }
        if (stru->stick.game == 1)
            push_list_win(stru, 2);
        if (stru->stick.game == 2)
            push_list_win(stru, 1);
        deleted_liste(stru);
        stru->stick.game = 0;
        play = 0;
        free(stru->stick.map);
        init_map(stru);
        init_struct2(stru);
    }
}

void ia_renforce(struct_t *stru)
{
    stru->liste1 = init_liste();
    stru->liste2 = init_liste();
    stru->listewin = init_liste();
    play_ia(stru);
}