/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** second_usr.c
*/

#include "navy.h"
#include "my.h"

int receive_attack(void)
{
    while (attack[3] == -1) {
        signal(SIGUSR2, touch);
        signal(SIGUSR1, missed);
    }
    if (attack[3] == 0)
        return 0;
    if (attack[3] == 1)
        return 1;
    return 2;
}

int game_usr2_cut(map_t *map, int *i)
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
    }
    if (is_win(map) == 1)
        return -1;
    free(b);
    return 0;
}

int game_usr2(map_t *map)
{
    int i = 0;
    int a = 0;

    while (map->game == 1) {
        if (i == 0) {
            display_map(map);
            receive_pos();
            is_touch(map);
        }
        if (is_win(map) == 1)
            return -1;
        my_printf("attack: ");
        if ((a = game_usr2_cut(map, &i)) != 0)
            return a;
        attack[0] = 0;
        attack[1] = 0;
    }
    return 0;
}

int second_usr(map_t *map, char *pid, char *pos)
{
    if (get_pos_boat(map, pos) == 84)
        return 84;
    map->pid = my_getnbr(pid);
    usleep(5000);
    if (kill(my_getnbr(pid), SIGUSR2) == -1)
        return 84;
    my_printf("my_pid: %d\nsuccessfully connected\n\n", getpid());
    send_pid(map);
    if (game_usr2(map) == 1)
        return 1;
    return 0;
}