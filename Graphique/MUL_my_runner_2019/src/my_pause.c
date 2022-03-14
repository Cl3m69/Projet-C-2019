/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** my_pause
*/

#include "../include/setup.h"

void my_pause2(m_t *st, list_t *liste)
{
    sfSprite *Spause2;
    sfTexture *Tpause2;
    sfVector2f Ppause2 = {50, 0};

    Tpause2 = sfTexture_createFromFile("sprite/pause1.png", NULL);
    Spause2 = sfSprite_create();
    sfSprite_setTexture(Spause2, Tpause2, sfTrue);
    sfSprite_setPosition(Spause2, Ppause2);
    sfRenderWindow_clear(st->setup.window, sfBlack);
    draw_parrallax(st);
    if (st->setup.ac == 2)
        draw_obstacle(st, liste);
    sfRenderWindow_drawSprite(st->setup.window, Spause2, NULL);
    sfRenderWindow_display(st->setup.window);
    st->setup.mouse = sfMouse_getPositionRenderWindow(st->setup.window);
    if (st->setup.mouse.x >= 50 && st->setup.mouse.x <= 100
    && st->setup.mouse.y >= 0 && st->setup.mouse.y <= 50
    && sfMouse_isButtonPressed(st->setup.button))
        st->setup.game = 1;
}

void my_pause(m_t *st, list_t *liste)
{
    sfSprite *Spause2;
    sfTexture *Tpause2;
    sfVector2f Ppause2 = {50, 0};

    Tpause2 = sfTexture_createFromFile("sprite/pause1.png", NULL);
    Spause2 = sfSprite_create();
    sfSprite_setTexture(Spause2, Tpause2, sfTrue);
    sfSprite_setPosition(Spause2, Ppause2);
    while (st->setup.game == 2) {
        while (sfRenderWindow_pollEvent(st->setup.window, &(st->setup.event))) {
            st->setup.button = sfMouseLeft;
            if (st->setup.event.type == sfEvtClosed)
                st->setup.game = 3;
        }
        my_pause2(st, liste);
    }
}