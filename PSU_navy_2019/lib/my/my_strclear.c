/*
** EPITECH PROJECT, 2019
** my_strclear.c
** File description:
** clear a str
*/

#include "../../include/my.h"

char *my_strclear(char *src)
{
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (src[i] == ' ')
        i++;
    while (src[i] != '\0') {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
