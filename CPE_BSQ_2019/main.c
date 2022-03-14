/*
** EPITECH PROJECT, 2019
** Main
** File description:
** BSQ
*/

#include "include/print.h"
#include "include/bsq.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av)
{
    square_h square;
    int **tab = NULL;
    char *buffer = NULL;
    struct stat size_h;

    if (ac != 2)
        return 84;
    stat(av[1], &size_h);
    square.size = size_h.st_size;
    get_lines_colums(av[1], &square.nbcolums, &square.nblines);
    //my_printf("%d, %d\n", square.nbcolums, square.nblines);
    buffer = get_buffer(buffer, av[1], square.nbcolums, square.nblines);
    tab = malloc_get_tab(tab, buffer, square.nbcolums, square.nblines);
    tab = get_position_square(tab, &square.posi, &square.posj, &square.nb);
    tab = put_X(tab, square.posi, square.posj, square.nb);
    display_buffer(tab, buffer);
    return 0;
}
