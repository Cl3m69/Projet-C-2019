/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct error
{
    int fd;
    int df;
}error_t;

typedef struct map
{
    char **mapxp;
    char **map;
    char *test;
    int win;
    int loose;
    int sizemap;
    int lines;
    int colums;
    int nbx;
    int checkx;
    int checko;
    int nbo;
    int px;
    int py;
}map_t;

void init_tab2(map_t *map);
void init_tab(map_t *map);
int check_error(map_t *map, int ac, char **av);
int sokoban(map_t *map);
int check_lose(map_t *map);
void key_left(map_t *map);
void key_right(map_t *map);
void key_down(map_t *map);
void key_up(map_t *map);

#endif /* !SOKOBAN_H_ */
