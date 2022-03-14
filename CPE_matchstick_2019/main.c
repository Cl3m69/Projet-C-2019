/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main
*/

#include "include/my.h"

void my_algo_ia(struct_t *stru)
{
    int i = 0;

    my_putstr("AI's turn...\n");
    if (get_iawin(stru) == 1);
    else {
        get_lineia(stru);
        get_matchia(stru);
    }
    check_win(stru, i);
    change_map(stru);
    my_putstr("AI removed ");
    my_put_nbr(stru->stick.matcheswr);
    my_putstr(" match(es) from line ");
    my_put_nbr(stru->stick.linewr);
    write(1, "\n", 1);
    my_display(stru);
    if (stru->stick.nb == 0)
        stru->stick.game = 1;
}

int my_game(struct_t *stru)
{
    int play = 0;

    while (stru->stick.game == 0) {
        my_putchar('\n');
        if (play % 2 == 0) {
            if (my_game_cut(stru) == 84)
                return 84;
        }
        else
            my_algo_ia(stru);
        play++;
    }
    return 0;
}

int main(int ac, char **av)
{
    struct_t stru;

    if (ac != 3 || check_error(av, &stru) == 84)
        return 84;
    srand(time(NULL));
    init_struct(&stru);
    ia_renforce(&stru);
    my_display(&stru);
    if (my_game(&stru) == 84)
        return 0;
    if (stru.stick.game == 2) {
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    my_putstr("I lost... snif... but I'll get you next time!!\n");
    return 1;
}