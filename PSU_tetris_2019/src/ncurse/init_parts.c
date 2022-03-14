/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_parts
*/

#include "tetris.h"

list_t *random_tetrimino(setup_t setup, int rand)
{
    for (int i = 0; i != rand && setup.tetriminos != 0; i++) {
        setup.tetriminos = setup.tetriminos->next;
    }
    return setup.tetriminos;
}

void init_parts_next(setup_t *setup)
{
    int i = 0;
    int a = 0;
    int b = 0;
    list_t *tetrimino;

    i = rand() % setup->tetriminos_nb;
    tetrimino = random_tetrimino(*setup, i);
    setup->colorpartsnext = tetrimino->color;
    i = 0;
    for (; tetrimino->data[i] != '\n'; i++);
    i++;
    setup->partsnext = malloc(sizeof(char *) *
    (tetrimino->data[2] - 48 + 1));
    for (; tetrimino->data[i] != 0; i++, a++, b = 0) {
        setup->partsnext[a] = malloc(sizeof(char) *
        tetrimino->data[0] - 48 + 2);
        for (; tetrimino->data[i] != '\n'; i++, b++)
            setup->partsnext[a][b] = tetrimino->data[i];
        setup->partsnext[a][b] = 0;
    }
    setup->partsnext[a] = NULL;
}

void init_parts(setup_t *setup)
{
    int i = 0;
    int a = 0;
    int b = 0;
    list_t *tetrimino;

    i = rand() % setup->tetriminos_nb;
    tetrimino = random_tetrimino(*setup, i);
    setup->colorparts = tetrimino->color;
    i = 0;
    for (; tetrimino->data[i] != '\n'; i++);
    i++;
    setup->parts = malloc(sizeof(char *) *
    (tetrimino->data[2] - 48 + 1));
    for (; tetrimino->data[i] != 0; i++, a++, b = 0) {
        setup->parts[a] = malloc(sizeof(char) *
        tetrimino->data[0] - 48 + 2);
        for (; tetrimino->data[i] != '\n'; i++, b++)
            setup->parts[a][b] = tetrimino->data[i];
        setup->parts[a][b] = 0;
    }
    setup->parts[a] = NULL;
}
