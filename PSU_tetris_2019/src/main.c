/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include "tetris.h"
#include <termios.h>

int mygetch(void)
{
    int ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int my_game(setup_t *setup, int i, int key)
{
    while (1) {
        key = getch();
        if (key == setup->key_quit[0])
            GAME_OVER;
        if (my_strcmp(setup->key_turn, tigetstr("kcuu1")) == 0 && key == KEY_UP)
            rotate_parts(setup);
        if (setup->key_turn[0] == key)
            rotate_parts(setup);
        display_setup(setup, setup->chrono);
        display_map(setup);
        if (i != 0)
            i = display_parts(setup, &setup->coord, i, key);
        if (i == 0) {
            deleted_lines(setup);
            setup->colorparts = setup->colorpartsnext;
            setup->parts = setup->partsnext;
            init_parts_next(setup);
            i = -1;
        }
        refresh();
    }
}

void init_struct(setup_t *setup)
{
    setup->coord.b = 0;
    setup->coord.i = 0;
    setup->coord.j = 0;
    setup->coord.time = 0;
    setup->coord.tmp = 0;
    setup->coord.x = check_y(setup->size) / 2;
    setup->coord.y = check_x(setup->size) / 2;
    setup->coord.z = 0;
}

int boucle_game(setup_t *setup)
{
    int key = -1;
    int i = -1;

    init_struct(setup);
    if (setup->coord.y * 2 + 4 > tgetnum("lines") ||
    setup->coord.x * 2 + 55 + 15 > tgetnum("cols")) {
        write(2, "Can't start because the terminal is too ", 40);
        write(2, "small, please try with a bigger terminal\n", 41);
        exit (84);
    }
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    init_map(setup);
    init_parts(setup);
    init_parts_next(setup);
    my_game(setup, i, key);
    endwin();
    return 0;
}

int main(int ac, char **av)
{
    setup_t setup;
    char ***opt;

    srand(time(NULL));
    if (check_error(ac, av, 0) == 84) {
        my_printf("error : Invalid argument, type %s --help.\n", av[0]);
        return 84;
    } if (check_error(ac, av, 1) == 1)
        return 0;
    opt = get_options_in_array(ac, av, 1, 0);
    if (opt == NULL) {
        my_printf("error : Invalid argument, type %s --help.\n", av[0]);
        return 84;
    }
    init_default_setup(&setup, opt);
    if (my_strcmp(setup.debug, "Yes") == 0) {
        display_debug(setup);
        mygetch();
    }
    boucle_game(&setup);
    return 0;
}