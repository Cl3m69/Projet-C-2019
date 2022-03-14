/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** get_buffer
*/

#include "../../include/my.h"
#include "../../include/print.h"
#include "../../include/bsq.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *get_buffer(char *buffer, char *av1, int nbcolums, int nblines)
{
    int fd = open(av1, O_RDONLY);
    char c = '0';

    buffer = malloc(sizeof(char) * nbcolums * nblines + nblines + 1);
    while (c != '\n') {
        read(fd, buffer, 1);
        c = buffer[0];
    }
    buffer = NULL;
    buffer = malloc(sizeof(char) * nbcolums * nblines + nblines + 1);
    read(fd, buffer, nbcolums * nblines + nblines);
    buffer[nbcolums * nblines + nblines] = 0;
    return (buffer);
}