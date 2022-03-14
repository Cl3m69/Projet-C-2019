/*
** EPITECH PROJECT, 2019
** MyHunter
** File description:
** setup
*/

#ifndef SETUP_H_
#define SETUP_H_

#include "hunter.h"

typedef struct setup
{
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
    sfVector2i mouse;
    sfSprite* Sbackground;
    sfTexture* Tbackground;
    sfSprite* Scible;
    sfTexture* Tcible;
    sfVector2f Pcible;
    sfMouseButton button;
    sfSprite* Svie;
    sfTexture* Tvie;
    sfVector2f Pvie;
    sfIntRect Rvie;
    int game;
}setup_h;

typedef struct menu
{
    sfSprite* SmenuP;
    sfTexture* TmenuP;
    sfVector2f PmenuP;
    sfIntRect RmenuP;
    sfSprite* SmenuO;
    sfTexture* TmenuO;
    sfVector2f PmenuO;
    sfIntRect RmenuO;
    sfSprite* SmenuE;
    sfTexture* TmenuE;
    sfVector2f PmenuE;
    sfIntRect RmenuE;
    sfSoundBuffer* sound;
    sfSound* sound_menu;
    int game;
}menu_h;

typedef struct game
{
    sfSprite* Sbird;
    sfTexture* Tbird;
    sfVector2f Pbird;
    sfClock* clock_bird;
    sfIntRect Rbird;
    sfSprite* Secur;
    sfTexture* Tecur;
    sfVector2f Pecur;
    sfSoundBuffer* sound;
    sfSound* sound_tir;
    sfTexture* Tregle;
    sfSprite* Sregle;
    sfTexture* Tback;
    sfSprite* Sback;
    int vitesse;
    int vie;
}game_h;

typedef struct jul
{
    sfSprite* Sjul;
    sfTexture* Tjul;
    sfVector2f Pjul;
    int ale;
    int ale1;
    int random1;
    int random2;
    int check;
}jul_h;

void option_game(setup_h *setup, game_h *game);
void target_init(setup_h *setup);
void menu_up(menu_h *menu);
void set_up(setup_h *setup);
void analyse_event(setup_h *setup, game_h *game);
void game_up(game_h *game);
void jul_up(jul_h *jul);
void menu_game(menu_h *menu, setup_h *setup);
void play_game(setup_h *setup, game_h *game, jul_h *jul);
void check_flag(int ac, char **av);

#endif /* !SETUP_H_ */