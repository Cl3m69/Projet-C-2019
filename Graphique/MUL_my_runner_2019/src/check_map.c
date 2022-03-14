/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** check_map
*/

#include "../include/setup.h"

int my_error(m_t *st)
{
    int n = 0;
    int j = 0;

    for (int i = 0; st->obs.buffer[i] != 0; i++) {
        if (st->obs.buffer[i] == '\n') {
            n++;
            j = 0;
        }
        if (st->obs.buffer[i] != '\n')
            j++;
        if (j >= 1000)
            return 84;
    }
    if (n != 6)
        return 84;
    return 0;
}

void my_malloc(m_t *st, int size)
{
    int i = 0;
    int j = 0;
    int l = 0;

    st->obs.map = malloc(sizeof(char *) * 7);
    while (st->obs.buffer[i] != 0) {
        st->obs.map[j] = malloc(sizeof(char) * size + 1);
        while (st->obs.buffer[i] != '\n') {
            st->obs.map[j][l] = st->obs.buffer[i];
            i++;
            l++;
        }
        st->obs.map[j][l] = 0;
        l = 0;
        j++;
        i++;
    }
    st->obs.map[j] = malloc(sizeof(char) * 1);
    st->obs.map[j][0] = 0;
}

int check_map(m_t *st, char *map)
{
    int fd = open(map, O_RDONLY);
    int e = 0;
    struct stat so;

    if (fd == -1)
        return 84;
    stat(map, &so);
    st->obs.buffer = malloc(sizeof(char) * so.st_size + 1);
    e = read(fd, st->obs.buffer, so.st_size);
    close(fd);
    st->obs.buffer[so.st_size] = 0;
    if (e == -1 || e > 6000)
        return 84;
    e = my_error(st);
    if (e == 84)
        return 84;
    my_malloc(st, so.st_size);
    return 0;
}