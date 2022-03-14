/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** malloc_get_tab
*/

#include "../../include/my.h"
#include "../../include/print.h"
#include "../../include/bsq.h"
#include <fcntl.h>
#include <stdlib.h>

int **malloc_get_tab(int **tab, char *buffer, int nbcolums, int nblines)
{
    int b = 0;
    int i = 0;
    int j = 0;

    tab = malloc(sizeof(int *) * (nblines + 1));
    for (; buffer[b] != 0; b++, i++) {
        tab[i] = malloc(sizeof(int) * (nbcolums + 2));
        for (; buffer[b] != '\n'; b++, j++) {
            if (buffer[b] == '.')
                tab[i][j] = 1;
            else if (buffer[b] == 'o')
                tab[i][j] = 0;
        }
        tab[i][j] = -5;
        j = 0;
    }
    tab[i] = malloc(sizeof(int) * 1);
    tab[i][0] = -5;
    return (tab);
}