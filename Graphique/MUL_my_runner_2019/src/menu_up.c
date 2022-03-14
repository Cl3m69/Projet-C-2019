/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** menu_up
*/

#include "../include/setup.h"

void menu_game2(m_t *st)
{
    sfRenderWindow_drawSprite(st->setup.window, st->menu.SmenuP, NULL);
    st->setup.mouse = sfMouse_getPositionRenderWindow(st->setup.window);
    sfSprite_setTextureRect(st->menu.SmenuP, st->menu.RmenuP);
    if (st->setup.mouse.x >= 500 && st->setup.mouse.x <= 800 &&
    st->setup.mouse.y >= 100 && st->setup.mouse.y <= 250) {
        st->menu.RmenuP.left = 300;
    }
    else
        st->menu.RmenuP.left = 0;
    if (st->setup.mouse.x >= 500 && st->setup.mouse.x <= 800 &&
    st->setup.mouse.y >= 100 && st->setup.mouse.y <= 250 &&
    st->setup.event.type == sfEvtMouseButtonPressed) {
        st->setup.game = 1;
    }
}

void menu_game(m_t *st, list_t *liste)
{
    draw_parrallax(st);
    if (st->setup.ac == 2)
        draw_obstacle(st, liste);
    menu_game2(st);
}

void menu_up(m_t *st)
{
    st->menu.PmenuP = (sfVector2f) {500, 100};
    st->menu.TmenuP = sfTexture_createFromFile("sprite/playmenu.png", NULL);
    st->menu.SmenuP = sfSprite_create();
    sfSprite_setTexture(st->menu.SmenuP, st->menu.TmenuP, sfTrue);
    st->menu.RmenuP.height = 150;
    st->menu.RmenuP.width = 300;
    st->menu.RmenuP.left = 0;
    st->menu.RmenuP.top = 0;
    sfSprite_setTextureRect(st->menu.SmenuP, st->menu.RmenuP);
    sfSprite_setPosition(st->menu.SmenuP, st->menu.PmenuP);
}