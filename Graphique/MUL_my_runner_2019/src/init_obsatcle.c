/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** init_obsatcle
*/

#include "../include/setup.h"

int add_element(list_t *liste, int x, int y)
{
    element_t *new = malloc(sizeof(*new));

    new->Sbox = sfSprite_create();
    new->Tbox = sfTexture_createFromFile("sprite/box.png", NULL);
    new->Pbox = (sfVector2f) {1000+(x*100), y*100};
    sfSprite_setTexture(new->Sbox, new->Tbox, sfTrue);
    sfSprite_setPosition(new->Sbox, new->Pbox);
    new->suivant = liste->premier;
    liste->premier = new;
    return 0;
}

list_t *init_ob(m_t *st)
{
    list_t *liste = malloc(sizeof(*liste));
    element_t *element = malloc(sizeof(*element));
    int i = 0;
    int j = 0;

    element->suivant = NULL;
    liste->premier = element;
    while (i < 6) {
        while (st->obs.map[i][j] != 0) {
            if (st->obs.map[i][j] == '1') {
                add_element(liste, j, i);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return liste;
}