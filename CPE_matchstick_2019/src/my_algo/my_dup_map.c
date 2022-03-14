/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_dup_map
*/

#include "../../include/my.h"

char **my_str_dup_iawin(struct_t *stru, ia_t *liste)
{
    int i = 0;
    char **tmp = malloc(sizeof(char *) * (stru->stick.line + 1));

    for (int j = 0; liste->map[i] != NULL; i++) {
        tmp[i] = malloc(sizeof(char) * (stru->stick.colonnes + 1));
        for (; liste->map[i][j] != 0; j++) {
            tmp[i][j] = liste->map[i][j];
        }
        tmp[i][j] = 0;
        j = 0;
    }
    tmp[i] = NULL;
    return tmp;
}

char **my_str_dup_ia(struct_t *stru)
{
    int i = 0;
    char **tmp = malloc(sizeof(char *) * (stru->stick.line + 1));

    for (int j = 0; stru->stick.map[i] != NULL; i++) {
        tmp[i] = malloc(sizeof(char) * (stru->stick.colonnes + 1));
        for (; stru->stick.map[i][j] != 0; j++) {
            tmp[i][j] = stru->stick.map[i][j];
        }
        tmp[i][j] = 0;
        j = 0;
    }
    tmp[i] = NULL;
    return tmp;
}

char **my_str_dup(struct_t *stru)
{
    int i = 0;
    char **tmp = malloc(sizeof(char *) * (stru->stick.line + 1));

    for (int j = 0; stru->stick.map[i] != NULL; i++) {
        tmp[i] = malloc(sizeof(char) * (stru->stick.colonnes + 1));
        for (; stru->stick.map[i][j] != 0; j++) {
            tmp[i][j] = stru->stick.map[i][j];
        }
        tmp[i][j] = 0;
        j = 0;
    }
    tmp[i] = NULL;
    return tmp;
}