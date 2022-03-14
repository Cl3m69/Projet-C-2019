/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** modif_para
*/

#include "../include/setup.h"

void modif_para2(m_t *st)
{
    sfSprite_setPosition(st->para.Ssaloon, st->para.Psaloon);
    if (st->para.Psaloon.x < -1350)
        st->para.Psaloon.x = 0;
    st->para.Psaloon.x -= 0.7;
    sfSprite_setPosition(st->para.Ssky, st->para.Psky);
    if (st->para.Psky.x < -1350)
        st->para.Psky.x = 0;
    st->para.Psky.x -= 0.1;
}

void modif_para(m_t *st)
{
    sfSprite_setPosition(st->para.Ssol, st->para.Psol);
    if (st->para.Psol.x < -1350)
        st->para.Psol.x = 0;
    st->para.Psol.x -= 1.5;
    sfSprite_setPosition(st->para.Scactus, st->para.Pcactus);
    if (st->para.Pcactus.x < -1350)
        st->para.Pcactus.x = 0;
    st->para.Pcactus.x -= 1;
    sfSprite_setPosition(st->para.Ssable, st->para.Psable);
    if (st->para.Psable.x < -1350)
        st->para.Psable.x = 0;
    st->para.Psable.x -= 0.7;
    sfSprite_setPosition(st->para.Sdunne, st->para.Pdunne);
    if (st->para.Pdunne.x < -1350)
        st->para.Pdunne.x = 0;
    st->para.Pdunne.x -= 0.3;
    modif_para2(st);
}

void clock_runner(m_t *st)
{
    if (sfClock_getElapsedTime(st->para.clock_runner).microseconds > 90000) {
        sfSprite_setPosition(st->para.Srunner, st->para.Prunner);
        st->para.Rrunner.left += 141;
        if (st->para.Rrunner.left >= 987)
            st->para.Rrunner.left = 0;
        if (st->setup.event.type == 4 && st->para.Prunner.y == 480)
            st->setup.jump = 1;
        if (st->setup.jump == 1) {
            if (st->para.Prunner.y <= 350)
                st->setup.jump = 2;
            st->para.Prunner.y -= 50;
        }
        if (st->setup.jump == 2) {
            if (st->para.Prunner.y >= 430)
                st->setup.jump = 0;
            st->para.Prunner.y += 50;
        }
        sfSprite_setTextureRect(st->para.Srunner, st->para.Rrunner);
        sfClock_restart(st->para.clock_runner);
    }
}