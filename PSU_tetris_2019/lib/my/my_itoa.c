/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_itoa
*/

#include "../../include/my.h"

char *my_itoa(int nb)
{
    int i = 0;
    int bb = nb;
    int signe;
    char *resultat = NULL;

    signe = nb < 0 ? 1 : 0;
    for ( ; nb / 10 > 0; i++)
        nb = nb / 10;
    resultat = malloc(sizeof(char) * i + 3);
    resultat[0] = bb % 10 + 48;
    for (int a = 1; bb / 10 > 0; a++) {
        bb = bb / 10;
        resultat[a] = bb % 10 + 48;
    }
    if (signe == 1) {
        resultat[i + 1] = '-';
        resultat[i + 2] = '\0';
    }
    else
        resultat[i + 1] = '\0';
    return (my_revstr(resultat));
}