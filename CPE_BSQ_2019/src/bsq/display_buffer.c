/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** display_buffer
*/

#include "../../include/my.h"
#include "../../include/print.h"
#include <unistd.h>

void display_buffer(int **tab, char *buffer)
{
    int i = 0;
    int a = 0;
    int j = 0;

    for (; tab[i][0] != -5; a++, i++) {
        while (tab[i][j] != -5) {
            if (tab[i][j] == 0)
                buffer[a] = 'o';
            if (tab[i][j] > 0)
                buffer[a] = '.';
            if (tab[i][j] == -1)
                buffer[a] = 'x';
            j++;
            a++;
        }
        buffer[a] = '\n';
        j = 0;
    }
    buffer[a] = 0;
    write(1, buffer, a);
}
