/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** init_liste
*/

#include "../../include/my.h"

list_t *init_liste(void)
{
    list_t *list = malloc(sizeof(*list));
    ia_t *ia = malloc(sizeof(*ia));

    ia->suivant = NULL;
    list->premier = ia;
    return list;
}