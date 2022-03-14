/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** first_user.c
*/

#include "navy.h"
#include "my.h"

int check_attack(char buf[6])
{
    if (buf[0] == '\n' || buf[1] == '\n') {
        my_printf("wrong position\n");
        return 84;
    }
    if (buf[2] == '\n') {
        if (!(buf[0] >= 65 && buf[0] <= 72)) {
            my_printf("wrong position\n");
            return 84;
        }
        if (!(buf[1] >= 49 && buf[1] <= 56)) {
            my_printf("wrong position\n");
            return 84;
        }
    }
    else {
        my_printf("wrong position\n");
        return 84;
    }
    return 0;
}

int game_usr1_cut(map_t *map, int *i)
{
    char *b = NULL;
    size_t busize = 6;

    if (getline(&b, &busize, stdin) == -1)
        return 1;
    if (check_attack(b) == 84)
        *i = 1;
    else {
        *i = 0;
        b[2] = 0;
        send_attack(map, b);
        touch_or_missed(map, b);
        if (is_win(map) == 1)
            return -1;
        receive_pos();
        is_touch(map);
    }
    free(b);
    return 0;
}

int game_usr1(map_t *map)
{
    int i = 0;
    int a = 0;

    while (map->game == 1) {
        if (i == 0)
            display_map(map);
        my_printf("attack: ");
        if ((a = game_usr1_cut(map, &i)) != 0)
            return a;
        if (is_win(map) == 1)
            return -1;
        attack[0] = 0;
        attack[1] = 0;
    }
    return 0;
}

int first_user(map_t *map, char *pos)
{
    if (get_pos_boat(map, pos) == 84)
        return 84;
    my_printf("my_pid: %d\nwaiting for enemy connection...\n\n", getpid());
    while (attack[4] == 0) {
        signal(SIGUSR2, connecte_sig);
    }
    attack[4] = 0;
    received_pid(map, 0);
    if (game_usr1(map) == 1)
        return 1;
    return 0;
}