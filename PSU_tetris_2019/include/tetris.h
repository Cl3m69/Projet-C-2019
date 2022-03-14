/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my.h
*/

#include <curses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <time.h>
#include <term.h>
#include "my.h"

#define GAME_OVER my_game_over(setup)

typedef struct list
{
    char *name;
    char *data;
    int color;
    char *size;
    struct list *next;
} list_t;

typedef struct coord
{
    int x;
    int y;
    int z;
    int b;
    int tmp;
    int i;
    int j;
    clock_t time;
}coord_t;

typedef struct setup
{
    char *key_lef;
    char *key_righ;
    char *key_turn;
    char *key_drop;
    char *key_quit;
    char *key_pause;
    char *next;
    int level;
    char *size;
    char *debug;
    int tetriminos_nb;
    struct list *tetriminos;
    clock_t chrono;
    int line;
    struct coord coord;
    int score;
    int high;
    int pause;
    int **map;
    char **parts;
    int colorparts;
    char **partsnext;
    int colorpartsnext;
} setup_t;

#ifndef TETRIS_H_
#define TETRIS_H_

int check_error(int ac, char **av, int i);
void create_list_tetriminos(list_t **list);
void display_tetriminos(list_t *list);
void init_default_setup(setup_t *setup, char ***opt);
void display_debug(setup_t setup);
char ***get_options_in_array(int ac, char **av, int i, int x);
void my_sort_list(list_t **begin);
void display_setup(setup_t *setup, clock_t chrono);
void display_score(setup_t *setup, clock_t chrono);
void my_rectangle(int x1, int x2, int y1, int y2);
void display_win(setup_t *setup);
int my_len_list(list_t *list);
int display_parts(setup_t *setup, coord_t *coord, int a, int key);
void init_parts(setup_t *setup);
void init_map(setup_t *setup);
int check_x(char *str);
int check_y(char *str);
int parting_tetriminos(char *data);
int error_options(char **av);
int error_long_options(char **av);
int useless_options(char **av);
void my_game_over(setup_t *setup);
int check_star(setup_t *setup, int z, int x);
void init_parts(setup_t *setup);
void display_map(setup_t *setup);
int size_is_good(char *data, int i);
void init_parts_next(setup_t *setup);
int display_next(setup_t *setup);
int check_if_is_tetrimino(char *file);
void change_name_tetrimino(list_t *element, char *file);
void key_press(setup_t *setup, coord_t *coord, int key, int max);
void function_press(setup_t *setup, coord_t *coord, int i);
int invalif_argument(char **av);
int check_parts2(setup_t *setup, coord_t *coord);
int check_parts(setup_t *setup, coord_t *coord);
int check_max_line(setup_t *setup);
void deleted_lines(setup_t *setup);
void rotate_parts(setup_t *setup);

#endif