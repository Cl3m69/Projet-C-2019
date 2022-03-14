/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** init_tetriminos.c
*/

#include "tetris.h"

void update_informations(list_t *element, int i, int tmp)
{
    char *x = "";
    char *y = "";
    char *color = "";

    if (my_strlen(element->data) < 4)
        return;
    for (; element->data[i] != '\n' && element->data[i] != '\0'; i++);
    i++;
    if (element->data[i] != 0 && i >= 4 &&
        parting_tetriminos(element->data) != 84) {
        for (; element->data[tmp] >= 48 && element->data[tmp] <= 57; tmp++)
            x = my_charcat(x, element->data[tmp]);
        for (tmp++; element->data[tmp] >= 48 && element->data[tmp] <= 57; tmp++)
            y = my_charcat(y, element->data[tmp]);
        element->size = my_strcat(x, "*");
        element->size = my_strcat(element->size, y);
        for (tmp++; element->data[tmp] >= 48 && element->data[tmp] <= 57; tmp++)
            color = my_charcat(color, element->data[tmp]);
        element->color = my_getnbr(color);
    } else
        element->size = "Error";
}

void add_fake_element(list_t **list)
{
    list_t *element = malloc(sizeof(list_t));

    element->name = "tmp";
    element->next = *list;
    *list = element;
}

void add_tetrimino(list_t **list, struct dirent *file)
{
    list_t *element = malloc(sizeof(list_t));
    int fd = open(my_strcat("./tetriminos/", file->d_name), O_RDONLY);
    struct stat s;

    stat(my_strcat("./tetriminos/", file->d_name), &s);
    element->data = malloc(sizeof(char) * (s.st_size + 1));
    change_name_tetrimino(element, file->d_name);
    if (fd != -1)
        read(fd, element->data, s.st_size);
    element->data[s.st_size] = 0;
    update_informations(element, 0, 0);
    element->next = *list;
    *list = element;
}

void create_list_tetriminos(list_t **list)
{
    DIR *src = opendir("./tetriminos/");
    struct dirent *info = readdir(src);

    while (info != 0) {
        if (check_if_is_tetrimino(info->d_name) != 84)
            add_tetrimino(list, info);
        info = readdir(src);
    }
    add_fake_element(list);
    my_sort_list(list);
}

void my_free_list(list_t *list)
{
    while (list != NULL) {
        free(list);
        list = list->next;
    }
}