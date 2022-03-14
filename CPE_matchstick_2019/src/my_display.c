/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_display
*/

#include "../include/my.h"

int my_game_cut(struct_t *stru)
{
    my_putstr("Your turn:\n");
    if (get_line(stru) == 84)
        return 84;
    if (get_match(stru) == 84)
        return 84;
    change_map(stru);
    my_putstr("Player removed ");
    my_put_nbr(stru->stick.matcheswr);
    my_putstr(" match(es) from line ");
    my_put_nbr(stru->stick.linewr);
    write(1, "\n", 1);
    my_display(stru);
    if (stru->stick.nb == 0)
        stru->stick.game = 2;
    return 0;
}

void my_display(struct_t *stru)
{
    for (int i = 0; stru->stick.map[i] != NULL; i++) {
        my_putstr(stru->stick.map[i]);
        my_putchar('\n');
    }
}