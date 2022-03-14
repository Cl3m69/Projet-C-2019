/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** init_map.c
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "navy.h"

int is_possible_to_update2(char *pos, int i, int nb)
{
    if (pos[i + 2] == pos[i + 5]) {
        if (pos[i + 6] - pos[i + 3] != nb - 49)
            return 84;
    } 
    else if (pos[i + 3] == pos[i + 6]) {
        if (pos[i + 5] - pos[i + 2] != nb - 49)
            return 84;
    } 
    else
        return 84;
    return 0;
}

int is_possible_to_update(char *pos)
{
    int i = 0;
    char nb = 0;

    while (i <= 24) {
        nb = pos[i];
        if (is_possible_to_update2(pos, i, nb) == 84)
            return 84;
        i += 8;
    }
    return 0;
}

int update_map(map_t *map, char *pos)
{
    char nb = 0;

    for (int i = 0, x = 0, y = 0, tmp = 0; i <= 24; i += 8, tmp = 0) {
        nb = pos[i];
        if (pos[i + 2] == pos[i + 5])
            tmp = 1;
        y = pos[i + 2] - (63 - (1 * (pos[i + 2] - 65)));
        x = pos[i + 3] - 47;
        for (int cmp = nb - 48; cmp > 0; cmp--) {
            if (map->map[x][y] == '.')
                map->map[x][y] = nb;
            else
                return 84;
            if (tmp == 1)
                x++;
            else
                y += 2;
        }
    }
    return 0;
}

int get_pos_boat(map_t *map, char *pos)
{
    int fd = open(pos, O_RDONLY);
    char *buff = malloc(sizeof(char) * 33);
    int u = 0;

    if (fd == -1)
        return 84;
    u = read(fd, buff, 33);
    if (u != 32)
        return 84;
    buff[32] = 0;
    buff = check_valid_file(buff);
    if (buff == NULL)
        return 84;
    if (is_possible_to_update(buff) == 84)
        return 84;
    if (update_map(map, buff) == 84)
        return 84;
    return 0;
}