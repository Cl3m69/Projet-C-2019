/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** parting_options.c
*/

#include "tetris.h"

int separate_opt(char ***result, int x)
{
    int i = 0;
    int y = 0;
    char *opt = malloc(sizeof(char) * my_strlen(result[x][0]));
    char *data = malloc(sizeof(char) * my_strlen(result[x][0]));

    for (; result[x][0][i] != '='; i++)
        opt[i] = result[x][0][i];
    opt[i] = 0;
    i++;
    for (; result[x][0][i] != 0; i++, y++)
        data[y] = result[x][0][i];
    if (data[0] == 0)
        return 84;
    data[y] = 0;
    result[x][0] = my_strcat("", opt);
    result[x][1] = my_strcat("", data);
    result[x][1] = (my_strcmp(" ", result[x][1]) != 0) ?
    my_strcat("", data) : "(space)";
    free(opt);
    free(data);
    return 0;
}

char ***get_options_in_array(int ac, char **av, int i, int x)
{
    char ***res = malloc(sizeof(char **) * (ac));

    for (; av[i] != 0; x++) {
        res[x] = malloc(sizeof(char *) * 2);
        if (av[i][0] == '-' && av[i][1] != 0)
            res[x][0] = my_strcat("", av[i]);
        i++;
        if (res[x][0] != 0 && res[x][0][0] == '-' && res[x][0][1] == '-'
            && my_strcmp("--without-next", res[x][0]) != 0 &&
            my_strcmp("--debug", res[x][0])) {
            if (separate_opt(res, x) == 84)
                return NULL;
        } else if (av[i] != NULL && av[i][0] != '-') {
            res[x][1] = my_strcat("", av[i]);
            if (res[x][1][0] == '$' && res[x][1][1] != 0)
                res[x][1] = my_strcat("\\", res[x][1]);
            i++;
        }
    }
    res[x] = 0;
    return res;
}