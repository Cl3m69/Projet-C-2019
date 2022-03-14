/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** init_struct
*/

#include "../include/setup.h"

void game_up2(game_h *game)
{
    game->Tecur = sfTexture_createFromFile("sprite/ecur.png", NULL);
    game->Secur = sfSprite_create();
    game->Pecur = (sfVector2f) {1075, 360};
    sfSprite_setTexture(game->Secur, game->Tecur, sfTrue);
    sfSprite_setPosition(game->Secur, game->Pecur);
    game->Tback = sfTexture_createFromFile("sprite/back.png", NULL);
    game->Sback = sfSprite_create();
    sfSprite_setTexture(game->Sback, game->Tback, sfTrue);
    game->Tregle = sfTexture_createFromFile("sprite/optionmenu.png", NULL);
    game->Sregle = sfSprite_create();
    sfSprite_setTexture(game->Sregle, game->Tregle, sfTrue);
}

void game_up(game_h *game)
{
    game_up2(game);
    game->Tbird = sfTexture_createFromFile("sprite/bird.png", NULL);
    game->Sbird = sfSprite_create();
    game->Pbird = (sfVector2f) {0, 0};
    sfSprite_setTexture(game->Sbird, game->Tbird, sfTrue);
    sfSprite_setPosition(game->Sbird, game->Pbird);
    game->Rbird.top = 0;
    game->Rbird.left = 0;
    game->Rbird.height = 110;
    game->Rbird.width = 110;
    sfSprite_setTextureRect(game->Sbird, game->Rbird);
    game->clock_bird = sfClock_create();
    game->sound = sfSoundBuffer_createFromFile("Sons/tir.ogg");
    game->sound_tir = sfSound_create();
    sfSound_setBuffer(game->sound_tir, game->sound);
    game->vie = 3;
    game->vitesse = 25;
}

void jul_up(jul_h *jul)
{
    jul->Pjul = (sfVector2f) {500, 420};
    jul->Tjul = sfTexture_createFromFile("sprite/jul.png", NULL);
    jul->Sjul = sfSprite_create();
    sfSprite_setTexture(jul->Sjul, jul->Tjul, sfTrue);
    sfSprite_setPosition(jul->Sjul, jul->Pjul);
    jul->check = 0;
}
