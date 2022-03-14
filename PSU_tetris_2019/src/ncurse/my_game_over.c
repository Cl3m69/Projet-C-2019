/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_game_over
*/

#include "tetris.h"

void my_deleted_node(list_t **list)
{
    list_t *deleted = *list;

    if (deleted != NULL) {
        free(deleted->data);
        free(deleted->name);
        free(deleted->size);
        *list = deleted->next;
        free(deleted);
    }
}

void my_free_all(setup_t *setup)
{
    for (int i = 0; setup->parts[i] != 0; i++)
        free(setup->parts[i]);
    free(setup->parts);
    for (int i = 0; setup->partsnext[i] != 0; i++)
        free(setup->partsnext[i]);
    free(setup->partsnext);
    for (int i = 0; setup->map[i] != 0; i++)
        free(setup->map[i]);
    free(setup->map);
    while (setup->tetriminos != 0)
        my_deleted_node(&(setup->tetriminos));
    free(setup->tetriminos);
}

void my_game_over(setup_t *setup)
{
    refresh();
    display_map(setup);
    clear();
    printw("Dommage t'as perdu...");
    refresh();
    usleep(1000000);
    endwin();
    my_free_all(setup);
    write(1, "\nGame Over !\n", 13);
    my_printf("Score = %d\n", setup->score);
    exit (0);
}