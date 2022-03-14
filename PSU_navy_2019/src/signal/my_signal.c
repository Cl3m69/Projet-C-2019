/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_signal
*/

#include "navy.h"
#include "my.h"

void quit_sig(int signo)
{
    if (signo == SIGUSR1) {
        attack[4] = -1;
    }
    else
        my_printf("pas de signal\n");
}

void missed(int signo)
{
    if (signo == SIGUSR1)
        attack[3] = 0;
}

void touch(int signo)
{
    if (signo == SIGUSR2)
        attack[3] = 1;
}

void nbx_sig(int signo)
{
    if (signo == SIGUSR2)
        attack[1]++;
    else
        my_printf("pas de signal\n");
}

void nby_sig(int signo)
{
    if (signo == SIGUSR2)
        attack[0]++;
    else
        my_printf("pas de signal\n");
}