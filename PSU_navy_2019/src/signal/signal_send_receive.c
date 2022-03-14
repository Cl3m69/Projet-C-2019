/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** receive_position
*/

#include "navy.h"
#include "my.h"

void connecte_sig(void)
{
    my_printf("enemy connected\n\n");
    attack[4] = 1;
}

void send_attack(map_t *map, char *buf)
{
    int y = buf[0] - (63 - (1 * (buf[0] - 65)));
    int x = buf[1] - 47;

    for (int a = 0; a < y; a++) {
        usleep(5000);
        kill(map->pid, SIGUSR2);
    }
    usleep(5000);
    kill(map->pid, SIGUSR1);
    for (int a = 0; a < x; a++) {
        usleep(5000);
        kill(map->pid, SIGUSR2);
    }
    usleep(5000);
    kill(map->pid, SIGUSR1);
}

void receive_pos(void)
{
    attack[4] = 0;
    my_printf("waiting for enemy's attack...\n");
    while (attack[4] != -1) {
        signal(SIGUSR2, nby_sig);
        signal(SIGUSR1, quit_sig);
    }
    attack[4] = 0;
    while (attack[4] != -1) {
        signal(SIGUSR2, nbx_sig);
        signal(SIGUSR1, quit_sig);
    }
    attack[4] = 0;
}

int is_touch(map_t *map)
{
    if (map->map[attack[1]][attack[0]] >= 48 &&
    map->map[attack[1]][attack[0]] <= 57) {
        usleep(5000);
        kill(map->pid, SIGUSR2);
        my_printf("%c%c: hit\n\n", attack[0] +
        (64 -(attack[0] / 2)), attack[1] + 47);
        change_map(map, 1);
    } else {
        usleep(5000);
        kill(map->pid, SIGUSR1);
        my_printf("%c%c: missed\n\n", attack[0] +
        (64 -(attack[0] / 2)), attack[1] + 47);
        change_map(map, 0);
    }
    return 0;
}

void touch_or_missed(map_t *map, char *buf)
{
    attack[3] = -1;
    while (attack[3] == -1) {
        signal(SIGUSR2, touch);
        signal(SIGUSR1, missed);
    }
    if (attack[3] == 0)
        my_printf("%c%c: missed\n\n", buf[0], buf[1]);
    if (attack[3] == 1)
        my_printf("%c%c: hit\n\n", buf[0], buf[1]);
    change_en_map(map, buf);
}