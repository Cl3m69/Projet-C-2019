/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_sort_list.c
*/

#include "tetris.h"

int my_len_list(list_t *list)
{
    int i = 0;

    while (list != NULL) {
        list = list->next;
        i++;
    }
    return i;
}

void swipe_nodes(list_t **prev, list_t **actual)
{
    list_t *cmp = (*actual)->next;

    (*actual)->next = cmp->next;
    cmp->next = (*actual);
    (*prev)->next = cmp;
}

void my_sort_list(list_t **begin)
{
    list_t *prev = *begin;
    list_t *actual = (*begin)->next;
    int n;
    int i = 0;

    if (actual == NULL)
        exit (84);
    while (actual->next != 0) {
        n = my_strcmp(actual->name, actual->next->name);
        if (n > 0) {
            swipe_nodes(&prev, &actual);
            prev = *begin;
            actual = (*begin)->next;
        } else {
            prev = prev->next;
            actual = actual->next;
        }
        i++;
    }
    (*begin) = (*begin)->next;
}