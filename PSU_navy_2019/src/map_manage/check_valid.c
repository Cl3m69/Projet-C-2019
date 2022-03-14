/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check_valid
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "navy.h"

char *check_valid_letters(char *buff)
{
    if (buff[29] < 65 || buff[29] > 72)
        return NULL;
    if (buff[3] < 48 || buff[3] > 56)
        return NULL;
    if (buff[6] < 48 || buff[6] > 56)
        return NULL;
    if (buff[11] < 48 || buff[11] > 56)
        return NULL;
    if (buff[14] < 48 || buff[14] > 56)
        return NULL;
    if (buff[19] < 48 || buff[19] > 56)
        return NULL;
    if (buff[22] < 48 || buff[22] > 56)
        return NULL;
    if (buff[27] < 48 || buff[27] > 56)
        return NULL;
    if (buff[30] < 48 || buff[30] > 56)
        return NULL;
    return buff;
}

char *check_valid_file(char *buff)
{
    if (my_strlen(buff) != 32)
        return NULL;
    if (buff[0] != '2' || buff[8] != '3' || buff[16] != '4' || buff[24] != '5')
        return NULL;
    if (buff[2] < 65 || buff[2] > 72)
        return NULL;
    if (buff[5] < 65 || buff[5] > 72)
        return NULL;
    if (buff[10] < 65 || buff[10] > 72)
        return NULL;
    if (buff[13] < 65 || buff[13] > 72)
        return NULL;
    if (buff[18] < 65 || buff[18] > 72)
        return NULL;
    if (buff[21] < 65 || buff[21] > 72)
        return NULL;
    if (buff[26] < 65 || buff[26] > 72)
        return NULL;
    return (check_valid_letters(buff));
}
