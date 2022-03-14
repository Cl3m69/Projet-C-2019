/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** get_columns
*/

#include "../../include/my.h"
#include "../../include/print.h"
#include "../../include/bsq.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void get_lines_colums(char *av1, int *nbcolums, int *nblines)
{
    int i = 0;
    int fd = open(av1, O_RDONLY);
    char *str = malloc(sizeof(char) * 1);

    for (int c = 0; c != 10; i++) {
        read(fd, str, 1);
        c = str[0];
    }
    str = malloc(sizeof(char) * i);
    close(fd);
    fd = open(av1, O_RDONLY);
    read(fd, str, i);
    *nblines = my_getnbr(str);
    i = 0;
    for (int c = 0; c != 10; i++) {
        read(fd, str, 1);
        c = str[0];
    }
    *nbcolums = i - 1;
    close(fd);
    free(str);
}