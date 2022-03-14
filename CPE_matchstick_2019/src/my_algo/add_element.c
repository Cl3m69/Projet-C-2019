/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** add_element
*/

#include "../../include/my.h"

void add_elementlistewin1(struct_t *stru, ia_t *liste)
{
    ia_t *new = malloc(sizeof(*new));

    new->line = liste->line;
    new->match = liste->match;
    new->map = my_str_dup_iawin(stru, liste);
    new->suivant = stru->listewin->premier;
    stru->listewin->premier = new;
}

void push_list_win(struct_t *stru, int nb)
{
    ia_t *list1 = stru->liste1->premier;
    ia_t *list2 = stru->liste2->premier;

    if (nb == 1) {
        while (list1->suivant != NULL) {
            add_elementlistewin1(stru, list1);
            list1 = list1->suivant;
        }
    }
    else {
        while (list2->suivant != NULL) {
            add_elementlistewin1(stru, list2);
            list2 = list2->suivant;
        }
    }
}

int get_matchiawin(struct_t *stru)
{
    ia_t *listewin = stru->listewin->premier;
    int check = 0;

    while (listewin->suivant != NULL) {
        for (int i = 0, j = 0; stru->stick.map[i] != NULL; i++, j = 0) {
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
    }
    return check;
}

int add_elementliste2(struct_t *stru)
{
    ia_t *new = malloc(sizeof(*new));

    new->line = stru->stick.linewr;
    new->match = stru->stick.matcheswr;
    new->map = my_str_dup_ia(stru);
    new->suivant = stru->liste2->premier;
    stru->liste2->premier = new;
    return 0;
}

int add_elementliste1(struct_t *stru)
{
    ia_t *new = malloc(sizeof(*new));

    new->line = stru->stick.linewr;
    new->match = stru->stick.matcheswr;
    new->map = my_str_dup_ia(stru);
    new->suivant = stru->liste1->premier;
    stru->liste1->premier = new;
    return 0;
}
