/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** parting_error_tetriminos.c
*/

#include "tetris.h"

int parting_tetriminos(char *data)
{
    int i = 0;
    int tmp = 0;

    for (; data[i] != '\n'; i++) {
        if ((data[i] < 48 || data[i] > 57) && data[i] != 32)
            return 84;
    }
    for (; data[i] != 0; i++) {
        if (data[i] != '*' && data[i] != '\n' && data[i] != ' ')
            return 84;
        if (data[i] == '*')
            tmp++;
    }
    if (tmp == 0)
        return 84;
    if (size_is_good(data, 0) == 84)
        return 84;
    return 0;
}

int count_line_number(char *data, int i)
{
    int count = 0;
    int tmp = 0;

    for (; data[i] != 0;) {
        for (count = 0; data[i] != '\n' && data[i] != 0; i++) {
            if (data[i] != 32)
                count++;
            else if (data[i + 1] == '*')
                count++;
        }
        if (tmp < count)
            tmp = count;
        if (data[i] != 0)
            i++;
    }
    return tmp;
}

void change_name_tetrimino(list_t *element, char *file)
{
    int i = 0;
    char *tmp = "";
    char *cmp = "";
    char *name = "";

    tmp = my_revstr(my_strcat(tmp, file));
    for (; tmp[i] != 0 && tmp[i] != '.'; i++)
        cmp = my_charcat(cmp, tmp[i]);
    for (i++; tmp[i] != 0; i++)
        name = my_charcat(name, tmp[i]);
    name = my_revstr(name);
    element->name = name;
}

int check_if_is_tetrimino(char *file)
{
    int i = 0;
    char *tmp = "";
    char *cmp = "";

    tmp = my_revstr(my_strcat(tmp, file));
    for (; tmp[i] != 0 && tmp[i] != '.'; i++)
        cmp = my_charcat(cmp, tmp[i]);
    if (my_strcmp(cmp, "") != 0) {
        cmp[i] = 0;
        if (my_strcmp(cmp, "onimirtet") != 0)
            return 84;
    } else
        return 84;
    return 0;
}

int size_is_good(char *data, int i)
{
    char *x = "";
    char *y = "";
    int tmp = 0;

    for (; data[i] >= 48 && data[i] <= 57; i++)
        x = my_charcat(x, data[i]);
    i++;
    for (; data[i] >= 48 && data[i] <= 57; i++)
        y = my_charcat(y, data[i]);
    for (; data[i - 1] != '\n'; i++);
    if (my_getnbr(x) == 0 || my_getnbr(y) == 0)
        return 84;
    if (count_line_number(data, i) != my_getnbr(x))
        return 84;
    for (; data[i] != 0; i++)
        tmp = (data[i] == '\n') ? tmp + 1: tmp;
    if (data[i - 1] != '\n')
        return 84;
    if (tmp != my_getnbr(y))
        return 84;
    return 0;
}
