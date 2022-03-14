/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** boucle_game.c
*/

#include "navy.h"
#include "my.h"

void display(char **map)
{
    for (int i = 0; i != 10; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

void display_map(map_t *map)
{
    my_printf("my positions:\n");
    display(map->map);
    my_printf("\nenemy's positions:\n");
    display(map->en_map);
    my_printf("\n");
}