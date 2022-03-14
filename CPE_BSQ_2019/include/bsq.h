/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

typedef struct square
{
    int nbcolums;
    int nblines;
    int posi;
    int posj;
    int nb;
    long size;
}square_h;

void get_lines_colums(char *av1, int *nbcolums, int *nblines);
void display_buffer(int **tab, char *buffer);
char *get_buffer(char *buffer, char *av1, int nbcolums, int nblines);
void get_lines_colums(char *av1, int *nbcolums, int *nblines);
int little_nb(int a, int b, int c);
int **get_position_square(int **tab, int *posi, int *posj, int *nb);
int **malloc_get_tab(int **tab, char *buffer, int nbcolums, int nblines);
int **put_X(int **tab, int posi, int posj, int nb);

#endif