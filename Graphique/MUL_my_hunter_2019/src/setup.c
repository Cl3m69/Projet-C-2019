/*
** EPITECH PROJECT, 2019
** MyHunter
** File description:
** setup
*/

#include "../include/setup.h"

void target_init(setup_h *setup)
{
    setup->mouse = sfMouse_getPositionRenderWindow(setup->window);
    setup->Pcible.x = setup->mouse.x - 40;
    setup->Pcible.y = setup->mouse.y - 40;
    sfSprite_setPosition(setup->Scible, setup->Pcible);
    sfRenderWindow_drawSprite(setup->window, setup->Scible, NULL);
}

void menu_up(menu_h *menu)
{
    menu->PmenuP = (sfVector2f) {500, 100};
    menu->TmenuP = sfTexture_createFromFile("sprite/menu.png", NULL);
    menu->SmenuP = sfSprite_create();
    menu->PmenuO = (sfVector2f) {500, 250};
    menu->TmenuO = sfTexture_createFromFile("sprite/menu.png", NULL);
    menu->SmenuO = sfSprite_create();
    menu->PmenuE = (sfVector2f) {500, 400};
    menu->TmenuE = sfTexture_createFromFile("sprite/menu.png", NULL);
    menu->SmenuE = sfSprite_create();
    menu->sound = sfSoundBuffer_createFromFile("Sons/pierre.ogg");
    menu->sound_menu = sfSound_create();
    sfSound_setBuffer(menu->sound_menu, menu->sound);
    sfSprite_setTexture(menu->SmenuP, menu->TmenuP, sfTrue);
    sfSprite_setTextureRect(menu->SmenuP, menu->RmenuP);
    sfSprite_setTexture(menu->SmenuO, menu->TmenuO, sfTrue);
    sfSprite_setTextureRect(menu->SmenuO, menu->RmenuO);
    sfSprite_setTexture(menu->SmenuE, menu->TmenuE, sfTrue);
    sfSprite_setTextureRect(menu->SmenuE, menu->RmenuE);
    sfSound_play(menu->sound_menu);
}

void set_up2(setup_h *setup)
{
    setup->Rvie.top = 0;
    setup->Rvie.left = 0;
    setup->Rvie.height = 50;
    setup->Rvie.width = 165;
}

void set_up(setup_h *setup)
{
    setup->game = 0;
    setup->Pcible = (sfVector2f) {100, 100};
    setup->Tbackground = sfTexture_createFromFile("sprite/foret.jpg", NULL);
    setup->Sbackground = sfSprite_create();
    setup->Pvie = (sfVector2f) {10, 600};
    setup->Tvie = sfTexture_createFromFile("sprite/vie.png", NULL);
    setup->Svie = sfSprite_create();
    sfSprite_setTexture(setup->Svie, setup->Tvie, sfTrue);
    set_up2(setup);
    sfSprite_setTexture(setup->Sbackground, setup->Tbackground, sfTrue);
    setup->Tcible = sfTexture_createFromFile("sprite/cible.png", NULL);
    setup->Scible = sfSprite_create();
    sfSprite_setTexture(setup->Scible, setup->Tcible, sfTrue);
    sfSprite_setPosition(setup->Scible, setup->Pcible);
    setup->mode = (sfVideoMode) {1350, 700, 32};
    setup->window = sfRenderWindow_create(setup->mode,
    "my hunter", sfResize | sfClose, NULL);
    setup->mouse = sfMouse_getPositionRenderWindow(setup->window);
    sfRenderWindow_setMouseCursorVisible(setup->window, 0);
}

void analyse_event(setup_h *setup, game_h *game)
{
    int ale = 0;

    srand(time(NULL));
    ale = 1 + rand()%500;
    setup->button = sfMouseLeft;
    if (setup->event.type == sfEvtClosed)
        sfRenderWindow_close(setup->window);
    if (setup->mouse.x >= game->Pbird.x - 50 && setup->mouse.x <= game->Pbird.x
    + 100 && setup->mouse.y >= game->Pbird.y && setup->mouse.y <= game->Pbird.y
    + 110 && setup->event.type == sfEvtMouseButtonPressed) {
        game->vitesse += 3;
        game->Pbird = (sfVector2f) {-300, ale};
    }
}
