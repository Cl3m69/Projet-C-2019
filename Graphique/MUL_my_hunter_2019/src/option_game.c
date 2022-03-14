/*
** EPITECH PROJECT, 2019
** MyHunter
** File description:
** option_game
*/

#include "../include/setup.h"
#include <unistd.h>

void option_game(setup_h *setup, game_h *game)
{
    if (setup->mouse.x >= 0 && setup->mouse.x <= 200 && setup->mouse.y >=
    0 && setup->mouse.y <= 200 && sfMouse_isButtonPressed(setup->button))
        setup->game = 0;
    setup->mouse = sfMouse_getPositionRenderWindow(setup->window);
    sfRenderWindow_drawSprite(setup->window, game->Sregle, NULL);
    sfRenderWindow_drawSprite(setup->window, game->Sback, NULL);
}

void check_flag(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0) {
        write(1, "Bienvenue dans mon jeu !\n", 25);
        write(1, "Dans le menu : option c'est les règles du jeu\n", 47);
        write(1, "Bonne chance a toi tu as 4 vies !\n", 34);
        write(1, "tu peux utiliser que la souris et le clic\n", 42);
        write(1, "Si tu as l'écran game over clique sur le noir pour", 50);
        write(1, " revenir au menu\n", 17);
    }
    else
        write(1, "bad flag (-h)\n", 14);
}