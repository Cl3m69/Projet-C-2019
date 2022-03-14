/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** get_nb
*/

#include "../include/my.h"

int check_errormatch2(struct_t *stru)
{
    int count = 0;

    for (int i = stru->stick.linewr, j = 1; stru->stick.map[i][j] != '*'; j++) {
        if (stru->stick.map[i][j] == '|')
            count++;
    }
    if (count < stru->stick.matcheswr) {
        my_putstr("Error: not enough matches on this line\n");
        return 84;
    }
    return 0;
}

int check_errormatch(struct_t *stru)
{
    if (stru->stick.matcheswr > stru->stick.matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(stru->stick.matches);
        my_putstr(" matches per turn\n");
        return 0;
    }
    if (stru->stick.matcheswr == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return 0;
    }
    if (stru->stick.matcheswr == -1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return 0;
    }
    if (check_errormatch2(stru) == 84)
        return 0;
    return 1;
}

int check_errorline(struct_t *stru, int check)
{
    if (stru->stick.linewr == 0 || stru->stick.linewr > stru->stick.line - 2) {
        my_putstr("Error: this line is out of range\n");
        return 0;
    }
    if (stru->stick.linewr == -1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return 0;
    }
    for (int i = 1; stru->stick.map[stru->stick.linewr][i] != '*'; i++) {
        if (stru->stick.map[stru->stick.linewr][i] == '|')
            check = 1;
    }
    if (check == 0) {
        my_putstr("Error: this line is out of range\n");
        return 0;
    }
    return 1;
}

int get_match(struct_t *stru)
{
    char buf[32];
    char *b = buf;
    size_t bufsize = 32;
    int error = 10;

    for (int i = 0, nb = 0; nb != 1; ) {
        my_putstr("Matches: ");
        i = getline(&b, &bufsize, stdin);
        if (i == -1)
            return 84;
        stru->stick.matcheswr = my_getnbr(buf);
        error = check_errormatch(stru);
        if (error == 1)
            nb = 1;
        if (error == 0) {
            if (get_line(stru) == 84)
                return 84;
        }
    }
    return 0;
}

int get_line(struct_t *stru)
{
    char buf[32];
    char *b = buf;
    size_t bufsize = 32;

    for (int nb = 0, check = 0, i = 0; nb != 1; i = 0, check = 0) {
        my_putstr("Line: ");
        i = getline(&b, &bufsize, stdin);
        if (i == -1)
            return 84;
        stru->stick.linewr = my_getnbr(buf);
        if (check_errorline(stru, check) == 1)
            nb = 1;
    }
    return 0;
}