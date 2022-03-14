/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** invalid_argument.c
*/

int invalif_argument(char **av)
{
    for (int i = 1; av[i] != 0; i++) {
        for (int x = 0; av[i][x] != 0; x++)
            if (av[i][x] < 32)
                return 84;
    }
    return 0;
}