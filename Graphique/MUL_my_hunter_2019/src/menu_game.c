/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu_game
*/

#include "../include/setup.h"

void if_e2(menu_h *menu, setup_h setup)
{
    if (setup.mouse.x >= 500 && setup.mouse.x <= 800 && setup.mouse.y >= 260
    && setup.mouse.y <= 380) {
        menu->RmenuO.top = 150;
        menu->RmenuO.left = 300;
        menu->RmenuO.height = 150;
        menu->RmenuO.width = 300;
    }
    else {
        menu->RmenuO.top = 150;
        menu->RmenuO.left = 0;
        menu->RmenuO.height = 150;
        menu->RmenuO.width = 300;
    }
}

void if_e3(menu_h *menu, setup_h setup)
{
    if (setup.mouse.x >= 500 && setup.mouse.x <= 800 && setup.mouse.y >= 400
    && setup.mouse.y <= 530) {
        menu->RmenuE.top = 300;
        menu->RmenuE.left = 300;
        menu->RmenuE.height = 150;
        menu->RmenuE.width = 300;
    }
    else {
        menu->RmenuE.top = 300;
        menu->RmenuE.left = 0;
        menu->RmenuE.height = 150;
        menu->RmenuE.width = 300;
    }
}

void if_el(menu_h *menu, setup_h setup)
{
    if (setup.mouse.x >= 500 && setup.mouse.x <= 800 && setup.mouse.y >= 100
    && setup.mouse.y <= 240) {
        menu->RmenuP.top = 0;
        menu->RmenuP.left = 300;
        menu->RmenuP.height = 150;
        menu->RmenuP.width = 300;
    }
    else {
        menu->RmenuP.top = 0;
        menu->RmenuP.left = 0;
        menu->RmenuP.height = 150;
        menu->RmenuP.width = 300;
    }
    if_e2(menu, setup);
    if_e3(menu, setup);
}

void menu_game(menu_h *menu, setup_h *setup)
{
    if_el(menu, *setup);
    sfSprite_setTextureRect(menu->SmenuP, menu->RmenuP);
    sfSprite_setPosition(menu->SmenuP, menu->PmenuP);
    sfRenderWindow_drawSprite(setup->window, menu->SmenuP, NULL);
    sfSprite_setTextureRect(menu->SmenuO, menu->RmenuO);
    sfSprite_setPosition(menu->SmenuO,  menu->PmenuO);
    sfRenderWindow_drawSprite(setup->window, menu->SmenuO, NULL);
    sfSprite_setTextureRect(menu->SmenuE, menu->RmenuE);
    sfSprite_setPosition(menu->SmenuE, menu->PmenuE);
    sfRenderWindow_drawSprite(setup->window, menu->SmenuE, NULL);
    if (setup->mouse.x >= 500 && setup->mouse.x <= 800 && setup->mouse.y >= 100
    && setup->mouse.y <= 240 && setup->event.type == sfEvtMouseButtonPressed)
        setup->game = 1;
    if (setup->mouse.x >= 500 && setup->mouse.x <= 800 && setup->mouse.y >= 260
    && setup->mouse.y <= 380 && setup->event.type == sfEvtMouseButtonPressed)
        setup->game = 3;
    if (setup->mouse.x >= 500 && setup->mouse.x <= 800 && setup->mouse.y >= 420
    && setup->mouse.y <= 560 && setup->event.type == sfEvtMouseButtonPressed)
        setup->game = 9;
}
