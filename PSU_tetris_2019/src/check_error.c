/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** check_error.c
*/

#include "my.h"
#include "tetris.h"

void display_help(char **av)
{
    my_printf("Usage: %s [options]\n", av[0]);
    my_printf("Options:\n");
    my_printf(" --help Display this help");
    my_printf(" -L --level={num} Start Tetris at level num (def: 1)\n");
    my_printf(" -l --key-left={K} Move the tetrimino");
    my_printf(" LEFT using the K key (def: left arrow):\n");
    my_printf(" -r --key-right=z{K} Move the tetrimino"); 
    my_printf("RIGHT using the K key (def: right arrow)");
    my_printf(" -t --key-turn={K} TURN the tetrimino clockwise");
    my_printf(" 90d using the K key (def: top arrow)\n");
    my_printf(" -d --key-drop={K} DROP the tetrimino using");
    my_printf(" the K key (def: down arrow)\n");
    my_printf(" -q --key-quit={K} QUIT the game");
    my_printf(" using the K key (def: ‘q’ key)\n");
    my_printf(" -p --key-pause={K} PAUSE/RESTART"); 
    my_printf("the game using the K key (def: space bar)\n");
    my_printf(" --map-size={row,col} Set the numbers of ");
    my_printf("rows and columns of the map (def: 20,10)\n");
    my_printf(" -w --without-next Hide next tetrimino (def: false)\n");
    my_printf(" -D --debug Debug mode (def: false)\n");
}

int check_long_opt(char **av)
{
    for (int i = 1; av[i] != 0; i++){
        if (av[i][0] == '-' && av[i][1] != 0 && av[i][1] == '-' &&
            my_strncmp(av[i], "--level=", 8) != 0 &&
            my_strncmp(av[i], "--key-left=", 11) != 0 &&
            my_strncmp(av[i], "--key-right=", 12) != 0 &&
            my_strncmp(av[i], "--key-turn=", 11) != 0 &&
            my_strncmp(av[i], "--key-drop=", 11) != 0 &&
            my_strncmp(av[i], "--key-quit=", 11) != 0 &&
            my_strncmp(av[i], "--key-pause=", 12) != 0 &&
            my_strncmp(av[i], "--map-size=", 11) != 0  &&
            my_strncmp(av[i], "--without-next", 14) != 0 &&
            my_strncmp(av[i], "--debug", 7) != 0 &&
            my_strncmp(av[i], "--help", 6) != 0)
            return 84;
    }
    return 0;
}

int check_good_args(char **av)
{
    for (int i = 1; av[i] != NULL; i++) {
        if (av[i][0] == '-' && av[i][1] != 0 && av[i][1] != '-' &&
            my_strcmp(av[i], "-L") != 0 && my_strcmp(av[i], "-l") != 0 &&
            my_strcmp(av[i], "-r") != 0 && my_strcmp(av[i], "-t") != 0 &&
            my_strcmp(av[i], "-d") != 0 && my_strcmp(av[i], "-q") != 0 &&
            my_strcmp(av[i], "-p") != 0 && my_strcmp(av[i], "-D") != 0 &&
            my_strcmp(av[i], "-w") != 0)
            return 84;
        if (av[i][0] == '-' && av[i][1] != 0 && av[i][1] != '-' &&
            (my_strcmp(av[i], "-L") == 0 || my_strcmp(av[i], "-l") == 0 ||
            my_strcmp(av[i], "-r") == 0 || my_strcmp(av[i], "-t") == 0 ||
            my_strcmp(av[i], "-d") == 0 || my_strcmp(av[i], "-q") == 0 ||
            my_strcmp(av[i], "-p") == 0) && (av[i + 1] == 0 ||
            av[i + 1][0] == 0))
            return 84;
        if (av[i][0] == '-' && av[i][1] == 0)
            return 84;
        if (av[i][0] != '-' && av[i - 1][0] != '-')
            return 84;
    }
    return 0;
}

int repo_exist(void)
{
    DIR *src = opendir("./tetriminos/");

    if (src == NULL)
        return 84;
    return 0;
}

int check_error(int ac, char **av, int i)
{
    if (ac == 2 && my_strcmp("--help", av[1]) == 0 && i == 1) {
        display_help(av);
        return 1;
    }
    if (check_good_args(av) == 84)
        return 84;
    if (check_long_opt(av) == 84)
        return 84;
    if (repo_exist() == 84)
        return 84;
    if (error_options(av) == 84)
        return 84;
    if (error_long_options(av) == 84)
        return 84;
    if (useless_options(av) == 84)
        return 84;
    if (invalif_argument(av) == 84)
        return 84;
    return 0;
}