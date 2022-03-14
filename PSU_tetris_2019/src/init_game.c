/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init_game.c
*/

#include "tetris.h"

void update_map_size(setup_t *setup, char *mapsize)
{
    char *tmp = malloc(sizeof(char) * 10);
    int i = 0;
    int y = 0;

    for (; mapsize[i] != ','; i++) {
        if (mapsize[i] >= 48 && mapsize[i] <= 57) {
            tmp[y] = mapsize[i];
            y++;
        }
    }
    tmp[y] = '*';
    i++;
    y++;
    for (; mapsize[i] != 0; i++) {
        if (mapsize[i] >= 48 && mapsize[i] <= 57) {
            tmp[y] = mapsize[i];
            y++;
        }
    }
    tmp[y] = 0;
    setup->size = my_strcat("", tmp);
}

void update_options_bis(setup_t *setup, char ***opt, int x)
{
    if (my_strcmp(opt[x][0], "-q") == 0 ||
        my_strcmp(opt[x][0], "--key-quit") == 0)
        setup->key_quit = opt[x][1];
    if (my_strcmp(opt[x][0], "-p") == 0 ||
        my_strcmp(opt[x][0], "--key-pause") == 0)
        setup->key_pause = opt[x][1];
    if (my_strcmp(opt[x][0], "--map-size") == 0) {
        update_map_size(setup, opt[x][1]);
    } if (my_strcmp(opt[x][0], "-w") == 0 ||
        my_strcmp(opt[x][0], "--without-next") == 0)
        setup->next = "No";
    if (my_strcmp(opt[x][0], "-D") == 0 ||
        my_strcmp(opt[x][0], "--debug") == 0)
        setup->debug = "Yes";
}

void update_options(setup_t *setup, char ***opt)
{
    for (int x = 0; opt[x] != 0; x++) {
        if (my_strcmp(opt[x][0], "-L") == 0 ||
            my_strcmp(opt[x][0], "--level") == 0)
            setup->level = my_getnbr(opt[x][1]);
        if (my_strcmp(opt[x][0], "-l") == 0 ||
            my_strcmp(opt[x][0], "--key-left") == 0)
            setup->key_lef = opt[x][1];
        if (my_strcmp(opt[x][0], "-r") == 0 ||
            my_strcmp(opt[x][0], "--key-right") == 0)
            setup->key_righ = opt[x][1];
        if (my_strcmp(opt[x][0], "-t") == 0 ||
            my_strcmp(opt[x][0], "--key-turn") == 0)
            setup->key_turn = opt[x][1];
        if (my_strcmp(opt[x][0], "-d") == 0 ||
            my_strcmp(opt[x][0], "--key-drop") == 0)
            setup->key_drop = opt[x][1];
        update_options_bis(setup, opt, x);
    }
}

void get_input_arrays(setup_t *setup)
{
    setupterm(NULL, fileno(stdout), NULL);
    setup->key_lef = tigetstr("kcub1");
    setup->key_righ = tigetstr("kcuf1");
    setup->key_turn = tigetstr("kcuu1");
    setup->key_drop = tigetstr("kcud1");
}

void init_default_setup(setup_t *setup, char ***opt)
{
    setup->tetriminos = NULL;
    setup->level = 1;
    get_input_arrays(setup);
    setup->key_quit = "q";
    setup->key_pause = "(space)";
    setup->size = "20*10";
    setup->next = "Yes";
    setup->debug = "No";
    setup->line = 0;
    setup->score = 0;
    setup->high = 0;
    setup->pause = 0;
    create_list_tetriminos(&(setup->tetriminos));
    setup->tetriminos_nb = my_len_list(setup->tetriminos);
    update_options(setup, opt);
}