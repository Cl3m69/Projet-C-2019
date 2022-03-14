/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** display
*/

#include "../../include/my.h"

void my_display_ia(struct_t *stru)
{
    for (int i = 0; stru->stick.map[i] != NULL; i++) {
        my_putstr(stru->stick.map[i]);
        my_putchar('\n');
    }
}