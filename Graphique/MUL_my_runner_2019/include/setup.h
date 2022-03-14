/*
** EPITECH PROJECT, 2019
** MyHunter
** File description:
** setup
*/

#ifndef SETUP_H_
#define SETUP_H_

#include "runner.h"

typedef struct setup
{
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
    sfVector2i mouse;
    sfMouseButton button;
    sfSprite* Spause;
    sfTexture* Tpause;
    sfSoundBuffer* soundbuf;
    sfSound* sound;
    sfClock* jumper;
    int jump;
    int ac;
    int game;
}setup_h;

typedef struct menu
{
    sfSprite* SmenuP;
    sfTexture* TmenuP;
    sfVector2f PmenuP;
    sfIntRect RmenuP;
    sfSoundBuffer* sound;
    sfSound* sound_menu;
    int game;
}menu_h;

typedef struct parrallax
{
    sfClock* clock_runner;
    sfSprite* Ssol;
    sfTexture* Tsol;
    sfVector2f Psol;
    sfSprite* Sdunne;
    sfTexture* Tdunne;
    sfVector2f Pdunne;
    sfSprite* Scactus;
    sfTexture* Tcactus;
    sfVector2f Pcactus;
    sfSprite* Ssable;
    sfTexture* Tsable;
    sfVector2f Psable;
    sfSprite* Ssky;
    sfTexture* Tsky;
    sfVector2f Psky;
    sfSprite* Ssaloon;
    sfTexture* Tsaloon;
    sfVector2f Psaloon;
    sfSprite* Srunner;
    sfTexture* Trunner;
    sfVector2f Prunner;
    sfIntRect Rrunner;
    int vitesse;
    int vie;
}parrallax_h;

typedef struct element
{
    sfSprite *Sdalton;
    sfTexture *Tdalton;
    sfVector2f Pdalton;
    sfSprite* Sbox;
    sfTexture* Tbox;
    sfVector2f Pbox;
    struct element *suivant;
}element_t;

typedef struct liste
{
    struct element *premier;
}list_t;

typedef struct obstacle
{
    char **map;
    char *buffer;
    int error;
}obst_h;

typedef struct main
{
    obst_h obs;
    parrallax_h para;
    menu_h menu;
    setup_h setup;
}m_t;


void init_up(m_t *st);
void modif_para(m_t *st);
void clock_runner(m_t *st);
int check_map(m_t *st, char *map);
void flag(void);
list_t *init_ob(m_t *st);
void menu_game(m_t *st, list_t *liste);
void my_pause(m_t *st, list_t *liste);
void menu_up(m_t *st);
void play_game(m_t *st, list_t *liste);
void draw_obstacle(m_t *st, list_t *liste);
void draw_parrallax(m_t *st);
void game_over(m_t *st, list_t *liste);

#endif /* !SETUP_H_ */