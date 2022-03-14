/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** init_struct
*/

#include "../include/setup.h"

void init_up3(m_t *st)
{
    sfSprite_setPosition(st->para.Srunner, st->para.Prunner);
    sfSprite_setTextureRect(st->para.Srunner, st->para.Rrunner);
    st->para.clock_runner = sfClock_create();
    st->setup.jumper = sfClock_create();
    st->setup.game = 0;
    st->setup.Tpause = sfTexture_createFromFile("sprite/pause.png", NULL);
    st->setup.Spause = sfSprite_create();
    sfSprite_setTexture(st->setup.Spause, st->setup.Tpause, sfTrue);
    st->setup.jump = 0;
    st->setup.soundbuf = sfSoundBuffer_createFromFile("sons/lucky.ogg");
    st->setup.sound = sfSound_create();
    sfSound_setBuffer(st->setup.sound, st->setup.soundbuf);
}

void init_up2(m_t *st)
{
    st->para.Psable = (sfVector2f) {0, 0};
    st->para.Tsable = sfTexture_createFromFile("sprite/sable.png", NULL);
    st->para.Ssable = sfSprite_create();
    sfSprite_setTexture(st->para.Ssable, st->para.Tsable, sfTrue);
    st->para.Psaloon = (sfVector2f) {0, -80};
    st->para.Tsaloon = sfTexture_createFromFile("sprite/saloon.png", NULL);
    st->para.Ssaloon = sfSprite_create();
    sfSprite_setPosition(st->para.Ssaloon, st->para.Psaloon);
    sfSprite_setTexture(st->para.Ssaloon, st->para.Tsaloon, sfTrue);
    st->para.Psky = (sfVector2f) {0, 0};
    st->para.Prunner = (sfVector2f) {100, 480};
    st->para.Trunner = sfTexture_createFromFile("sprite/runner.png", NULL);
    st->para.Srunner = sfSprite_create();
    sfSprite_setTexture(st->para.Srunner, st->para.Trunner, sfTrue);
    st->para.Rrunner.height = 126;
    st->para.Rrunner.width = 141;
    st->para.Rrunner.left = 0;
    st->para.Rrunner.top = 0;
    init_up3(st);
}

void init_up(m_t *st)
{
    st->setup.mode = (sfVideoMode) {1350, 700, 32};
    st->setup.window = sfRenderWindow_create(st->setup.mode,
    "MY RUNNER", sfResize | sfClose, NULL);
    st->setup.mouse = sfMouse_getPositionRenderWindow(st->setup.window);
    st->para.Tsky = sfTexture_createFromFile("sprite/sky.png", NULL);
    st->para.Ssky = sfSprite_create();
    sfSprite_setTexture(st->para.Ssky, st->para.Tsky, sfTrue);
    st->para.Psol = (sfVector2f) {0, 0};
    st->para.Tsol = sfTexture_createFromFile("sprite/sol.png", NULL);
    st->para.Ssol = sfSprite_create();
    sfSprite_setTexture(st->para.Ssol, st->para.Tsol, sfTrue);
    st->para.Pdunne = (sfVector2f) {0, 0};
    st->para.Tdunne = sfTexture_createFromFile("sprite/dune.png", NULL);
    st->para.Sdunne = sfSprite_create();
    sfSprite_setTexture(st->para.Sdunne, st->para.Tdunne, sfTrue);
    st->para.Pcactus = (sfVector2f) {0, 0};
    st->para.Tcactus = sfTexture_createFromFile("sprite/cactus.png", NULL);
    st->para.Scactus = sfSprite_create();
    sfSprite_setTexture(st->para.Scactus, st->para.Tcactus, sfTrue);
    init_up2(st);
}
