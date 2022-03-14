/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "my.h"
#include "navy.h"

void free_map(map_t *map)
{
    for (int i = 0; i != 10; i++)
        free(map->map[i]);
    free(map->map);
    for (int i = 0; i != 10; i++)
        free(map->en_map[i]);
    free(map->en_map);
}

void init_struct(map_t *map)
{
    attack[0] = 0;
    attack[1] = 0;
    attack[2] = 0;
    attack[3] = 0;
    attack[4] = 0;
    attack[5] = 0;
    map->pid = 0;
    map->check = 0;
    map->game = 1;
    map->map = NULL;
    map->en_map = NULL;
    map->win = 0;
    map->en_win = 0;
    create_map(&map->map);
    create_map(&map->en_map);
}

int main(int ac, char **av)
{
    map_t map;
    int i = 0;

    init_struct(&map);
    map.check = check_error(ac, av);
    if (map.check == 84 || map.check == 0)
        return map.check;
    if ((i = init_game(&map, ac, av)) > 0) {
        if (i == 1)
            return 0;
        return i;
    }
    display_map(&map);
    free_map(&map);
    if (map.game == 0) {
        my_printf("I won\n");
        return 0;
    }
    my_printf("Enemy won\n");
    return 1;
}