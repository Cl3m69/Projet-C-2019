/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** my_draw
*/

#include "../include/setup.h"

void draw_parrallax(m_t *st)
{
    sfRenderWindow_drawSprite(st->setup.window, st->para.Ssky, NULL);
    sfRenderWindow_drawSprite(st->setup.window, st->para.Sdunne, NULL);
    sfRenderWindow_drawSprite(st->setup.window, st->para.Ssable, NULL);
    sfRenderWindow_drawSprite(st->setup.window, st->para.Ssaloon, NULL);
    sfRenderWindow_drawSprite(st->setup.window, st->para.Scactus, NULL);
    sfRenderWindow_drawSprite(st->setup.window, st->para.Ssol, NULL);
    sfRenderWindow_drawSprite(st->setup.window, st->para.Srunner, NULL);
    if (st->setup.game == 1)
        modif_para(st);
    if (st->setup.game != 2)
        clock_runner(st);
}

void draw_obstacle(m_t *st, list_t *liste)
{
    element_t *list = liste->premier;

    while (list->suivant != NULL) {
        if (st->setup.game == 1)
            list->Pbox.x -= 1.5;
        sfSprite_setPosition(list->Sbox, list->Pbox);
        sfRenderWindow_drawSprite(st->setup.window, list->Sbox, NULL);
        list = list->suivant;
    }
}
