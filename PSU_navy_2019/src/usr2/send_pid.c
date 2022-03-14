/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** pid_manage.c
*/

#include "navy.h"
#include "my.h"

void send_pid(map_t *map)
{
    char *pid = my_itoa(getpid());
    int d = 0;

    for (int i = 0; pid[i] != 0; i++) {
        d = pid[i] - 48;
        if (d == 0)
            d = 10;
        for (int a = 0; a < d; a++) {
            usleep(5000);
            kill(map->pid, SIGUSR2);
        }
        usleep(5000);
        kill(map->pid, SIGUSR1);
    }
    usleep(5000);
    kill(map->pid, SIGUSR1);
}