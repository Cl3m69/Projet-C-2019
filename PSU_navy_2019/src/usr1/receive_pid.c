/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** receive_pid.c
*/

#include "navy.h"
#include "my.h"

void nbpid_sig(int signo)
{
    if (signo == SIGUSR2) {
        attack[5] = 0;
        attack[3]++;
    }
    else
        my_printf("pas de signal\n");
}

void quit_sig_pid(int signo)
{
    if (signo == SIGUSR1) {
        attack[5]++;
        attack[4] = -1;
    }
    else
        my_printf("pas de signal\n");
}

void received_pid(map_t *map, int i)
{
    char *pid = malloc(sizeof(char) * 10);

    for (int check = 0; check == 0; attack[3] = 0) {
        while (attack[4] != -1) {
            signal(SIGUSR2, nbpid_sig);
            signal(SIGUSR1, quit_sig_pid);
        }
        attack[4] = 0;
        if (attack[5] > 1)
            check = -1;
        else {
            if (attack[3] == 10)
                pid[i] = '0';
            else
                pid[i] = attack[3] + 48;
            i++;
        }
    }
    attack[5] = 0;
    pid[i] = 0;
    map->pid = my_getnbr(pid);
}