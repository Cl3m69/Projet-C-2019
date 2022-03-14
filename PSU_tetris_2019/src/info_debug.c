/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** info_debug.c
*/

#include "tetris.h"

void display_tetriminos(list_t *list)
{
    int i = 0;

    while (list != 0) {
        if (list->size != 0 && my_strcmp("Error", list->size) != 0) {
            my_printf("Tetriminos : Name %s : Size %s : Color %d :\n",
            list->name, list->size, list->color);
            for (; list->data[i] != '\n'; i++);
            i++;
            for (; list->data[i] != 0; i++)
                my_putchar(list->data[i]);
        } else
            my_printf("Tetriminos : Name %s : Error\n", list->name);
        list = list->next;
        i = 0;
    }
}

void print_key_value(char *key, char *value)
{
    int i = 0;

    my_printf("Key %s : ", key);
    while (value[i] != '\0') {
        if (value[i] == ' ')
            my_putstr("(space)");
        else if (value[i] == 27)
            my_putstr("^E");
        else
            my_putchar(value[i]);
        i++;
    }
    my_putchar('\n');
}

void display_debug(setup_t setup)
{
    my_printf("*** DEBUG MODE ***\n");
    print_key_value("Left", setup.key_lef);
    print_key_value("Right", setup.key_righ);
    print_key_value("Turn", setup.key_turn);
    print_key_value("Drop", setup.key_drop);
    my_printf("Key Quit : %s\n", setup.key_quit);
    my_printf("Key Pause : %s\n", setup.key_pause);
    my_printf("Next : %s\n", setup.next);
    my_printf("Level : %d\n", setup.level);
    my_printf("Size : %s\n", setup.size);
    my_printf("Tetriminos : %d\n", setup.tetriminos_nb);
    display_tetriminos(setup.tetriminos);
    my_printf("Press any key to start Tetris\n");
}
