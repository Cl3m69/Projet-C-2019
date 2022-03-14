/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** game_over
*/

#include "../include/setup.h"

void game_over(m_t *st, list_t *liste)
{
    sfSprite* Sover;
    sfTexture* Tover;

    Tover = sfTexture_createFromFile("sprite/over.png", NULL);
    Sover = sfSprite_create();
    sfSprite_setTexture(Sover, Tover, sfTrue);
    sfRenderWindow_clear(st->setup.window, sfBlack);
    sfRenderWindow_drawSprite(st->setup.window, Sover, NULL);
    if (st->setup.event.type == sfEvtMouseButtonPressed)
        st->setup.game = 3;
}