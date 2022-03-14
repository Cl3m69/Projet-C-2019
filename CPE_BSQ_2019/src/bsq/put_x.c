/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** put_x
*/

#include "../../include/my.h"
#include "../../include/print.h"
#include "../../include/bsq.h"
#include <fcntl.h>
#include <stdlib.h>

int **put_X(int **tab, int posi, int posj, int nb)
{
    int i = posi;
    int j = posj;
    int a = 0;

    while (nb > 0) {
        while (a < nb) {
            tab[i][j - a] = -1;
            a++;
        }
        a = 0;
        while (a < nb) {
            tab[i - a][j] = -1;
            a++;
        }
        a = 0;
        j -= 1;
        i -= 1;
        nb--;
    }
    return tab;
}
