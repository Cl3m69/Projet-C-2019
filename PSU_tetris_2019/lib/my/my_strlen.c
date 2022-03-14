/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Strlen
*/

int my_strlen(char *str)
{
    int compteur = 0;

    while (str[compteur] != 0)
        compteur++;
    return compteur;
}
