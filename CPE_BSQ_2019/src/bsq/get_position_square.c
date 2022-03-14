/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** get_position_square
*/

#include "../../include/my.h"
#include "../../include/print.h"
#include "../../include/bsq.h"
#include <fcntl.h>
#include <stdlib.h>

int little_nb(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

void get_position_square2(int **tab, int **posi, int **posj, int **nb)
{
    int i = 0;
    int j = 0;

    while (tab[i][j] != -5) {
        if (**nb < tab[i][j]) {
            **nb = tab[i][j];
            **posj = j;
            **posi = i;
        }
        j++;
    }
    while (tab[i][0] != -5) {
        if (**nb < tab[i][0]) {
            **nb = tab[i][0];
            **posj = j;
            **posi = i;
        }
        i++;
    }
}

int **get_position_square(int **tab, int *posi, int *posj, int *nb)
{
    int a = 0;
    int c = 0;

    *nb = 0;
    get_position_square2(tab, &posi, &posj, &nb);
    for (int i = 1, j = 1, b = 0; tab[i][0] != -5; i++, j = 1) {
        for (; tab[i][j] != -5; j++) {
            a = tab[i][j - 1];
            b = tab[i - 1][j];
            c = tab[i - 1][j - 1];
            a = little_nb(a, b, c);
            if (tab[i][j] != 0)
                tab[i][j] += a;
            if (tab[i][j] > *nb) {
                *nb = tab[i][j];
                *posj = j;
                *posi = i;
            }
        }
    }
    return tab;
}