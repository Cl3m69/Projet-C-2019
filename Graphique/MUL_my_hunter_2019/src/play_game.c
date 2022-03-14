/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** play_game
*/

#include "../include/setup.h"

void manage_life(setup_h *setup)
{
    sfSprite_setTextureRect(setup->Svie, setup->Rvie);
    sfSprite_setPosition(setup->Svie, setup->Pvie);
    sfRenderWindow_drawSprite(setup->window, setup->Svie, NULL);
}

void manage_bird(setup_h *setup, game_h *game)
{
    if (sfClock_getElapsedTime(game->clock_bird).microseconds > 90000) {
        sfSprite_setPosition(game->Sbird, game->Pbird);
        game->Pbird.x += game->vitesse;
        if (game->Pbird.x >= 1460) {
            setup->Rvie.width -= 55;
            if (game->vie == 0) {
                game->vitesse = 25;
                setup->Rvie.width = 165;
                setup->game = 2;
                game->vie = 4;
            }
            game->Pbird.x = -20;
            game->vie--;
        }
        game->Rbird.left += 110;
        if (game->Rbird.left == 330) {
            game->Rbird.left = 0;
            game->Pbird.x += game->vitesse;
        }
        sfClock_restart(game->clock_bird);
    }
}

void manage_jul(setup_h *setup, jul_h *jul)
{
    if (jul->check == 0) {
        jul->random1 = rand()%1200;
        jul->random2 = rand()%550;
        jul->ale = rand()%700;
    }
    if (jul->ale == 8) {
        jul->Pjul = (sfVector2f) {jul->random1, jul->random2};
        sfSprite_setPosition(jul->Sjul, jul->Pjul);
        sfRenderWindow_drawSprite(setup->window, jul->Sjul, NULL);
        jul->check = 1;
    }
    jul->ale1 = rand()%1100;
    if (jul->ale1 == 8 && jul->check == 1) {
        jul->Pjul = (sfVector2f) {-500, -420};
        jul->check = 0;
    }
}

void manage_squirrel(setup_h *setup, game_h *game)
{
    sfSprite_setPosition(game->Secur, game->Pecur);
    sfRenderWindow_drawSprite(setup->window, game->Secur, NULL);
    if (setup->mouse.x >= 1080 && setup->mouse.x <= 1300 && setup->mouse.y >=
    300 && setup->mouse.y <= 400 && setup->event.type ==
    sfEvtMouseButtonPressed)
        game->Pecur = (sfVector2f) {-100, -100};
}

void play_game(setup_h *setup, game_h *game, jul_h *jul)
{
    manage_squirrel(setup, game);
    manage_jul(setup, jul);
    sfSprite_setTextureRect(game->Sbird, game->Rbird);
    sfRenderWindow_drawSprite(setup->window, game->Sbird, NULL);
    manage_bird(setup, game);
    manage_life(setup);
    if (setup->event.type == sfEvtMouseButtonPressed)
        sfSound_play(game->sound_tir);
}
