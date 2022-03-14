/*
** EPITECH PROJECT, 2019
** MyHunter
** File description:
** main
*/

#include "include/setup.h"

void game_over(setup_h *setup)
{
    sfSprite* Sover;
    sfTexture* Tover;

    Tover = sfTexture_createFromFile("sprite/over.png", NULL);
    Sover = sfSprite_create();
    sfSprite_setTexture(Sover, Tover, sfTrue);
    sfRenderWindow_clear(setup->window, sfBlack);
    sfRenderWindow_drawSprite(setup->window, Sover, NULL);
    if (setup->event.type == sfEvtMouseButtonPressed)
        setup->game = 0;
}

void open_game(menu_h menu, setup_h *setup, game_h *game, jul_h *jul)
{
    switch (setup->game)
    {
    case 0:
        menu_game(&menu, setup);
        break;
    case 1:
        play_game(setup, game, jul);
        break;
    case 2:
        game_over(setup);
        break;
    case 3:
        option_game(setup, game);
        break;
    case 9:
        sfRenderWindow_close(setup->window);
        break;
    }
}

void destroy(menu_h *menu, game_h *game)
{
    sfSound_stop(menu->sound_menu);
    sfSound_destroy(menu->sound_menu);
    sfSoundBuffer_destroy(menu->sound);
    sfSound_stop(game->sound_tir);
    sfSound_destroy(game->sound_tir);
    sfSoundBuffer_destroy(game->sound);
}

void main2(menu_h *menu, setup_h *setup, game_h *game, jul_h *jul)
{
    while (sfRenderWindow_isOpen(setup->window)) {
        while (sfRenderWindow_pollEvent(setup->window, &(setup->event)))
            analyse_event(setup, game);
        sfRenderWindow_clear(setup->window, sfBlack);
        sfRenderWindow_drawSprite(setup->window, setup->Sbackground, NULL);
        open_game(*menu, setup, game, jul);
        target_init(setup);
        sfRenderWindow_display(setup->window);
    }
}

int main(int ac, char **av)
{
    setup_h setup;
    menu_h menu;
    game_h game;
    jul_h jul;

    if (ac > 1) {
        check_flag(ac, av);
        return 84;
    }
    menu_up(&menu);
    set_up(&setup);
    game_up(&game);
    jul_up(&jul);
    main2(&menu, &setup, &game, &jul);
    destroy(&menu, &game);
    return 0;
}