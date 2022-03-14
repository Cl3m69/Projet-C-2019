/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** 
*/

#include "../../include/my.h"

int my_strcmp(char *nb1, char *nb2)
{
    int i = 0;
    int j = 0;

    while ((nb1[i] != '\0' || nb2[j] != '\0') && nb1[i] == nb2[j]) {
        j++;
        i++;
    }
    if (nb1[i] < nb2[j])
        return (-1);
    else if (nb1[i] > nb2[j])
        return (1);
    else
        return (0);
}
