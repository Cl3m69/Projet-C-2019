/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** strcat
*/

#include "../../include/my.h"

char *my_charcat(char *dest, char new)
{
    char *result = malloc(sizeof(char) * (my_strlen(dest) + 2));
    int x = 0;

    for (int i = 0; dest[i] != 0; x++, i++)
        result[x] = dest[i];
    result[x] = new;
    result[x + 1] = 0;
    return result;
}

char *my_strcat(char *dest, char *new)
{
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(new) + 1));
    int x = 0;

    for (int i = 0; dest[i] != 0; x++, i++)
        res[x] = dest[i];
    for (int i = 0; new[i] != 0; x++, i++)
        res[x] = new[i];
    res[x] = 0;
    return res;
}
