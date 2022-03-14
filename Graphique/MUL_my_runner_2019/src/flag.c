/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** flag
*/

#include "../include/setup.h"

void flag(void)
{
    write(1, "Bienvenue dans mon jeu de rantanplan !\n\n", 40);
    write(1, "Si vous voulez jouer avec des obstacles ajouter en ", 51);
    write(1, "argument une map.\nLa map doit contenir que des '1'     ", 55);
    write(1, " et des espaces.\nLe '1' feras spawn une caisse\n", 47);
    write(1, "Attention vous devez ecrire que sur les 7 premieres lignes", 58);
    write(1, ".\nChaque lignes doit etre suivit d'un retour de ligne \\n", 56);
    write(1, "\n\nEXEMPLE : A la source du repo une map est presente", 52);
    write(1, ", vous pouvez la modifier mais ATTENTION !\n", 43);
    write(1, "Ne depasser pas 1000 caracteres par ligne et 7 lignes\n", 54);
    write(1, "Pour sauter appuyer sur space, pour gagner il faut finir ", 57);
    write(1, "la map, si vous touchez un obstacles vous avez perdus\n", 54);
}