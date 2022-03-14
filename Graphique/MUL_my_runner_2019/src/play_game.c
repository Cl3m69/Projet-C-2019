/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** play_game
*/

#include "../include/setup.h"

void colision(m_t *st, list_t *liste)
{
    element_t *list = liste->premier;

    while (list->suivant != NULL) {
        sfSprite_setPosition(st->para.Srunner, st->para.Prunner);
        if (list->Pbox.x > 100 && list->Pbox.x < 230 && list->Pbox.y >
        st->para.Prunner.y && list->Pbox.y < st->para.Prunner.y +
        126 && st->setup.jump == 0)
            st->setup.game = 4;
        list = list->suivant;
    }
}

void play_game(m_t *st, list_t *liste)
{
    draw_parrallax(st);
    if (st->setup.ac == 2 && st->setup.game == 1)
        draw_obstacle(st, liste);
    if (st->setup.game == 1)
        sfRenderWindow_drawSprite(st->setup.window, st->setup.Spause, NULL);
    st->setup.mouse = sfMouse_getPositionRenderWindow(st->setup.window);
    if (st->setup.mouse.x >= 0 && st->setup.mouse.x <= 50
    && st->setup.mouse.y >= 0 && st->setup.mouse.y <=
    50 && sfMouse_isButtonPressed(st->setup.button))
        st->setup.game = 2;
    if (st->setup.ac == 2)
        colision(st, liste);
}