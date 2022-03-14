/*
** EPITECH PROJECT, 2019
** main
** File description:
** test pour graphique
*/

#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Listener.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundBufferRecorder.h>
#include <SFML/Audio/SoundRecorder.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/SoundStream.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int score1 = 0;
    int score2 = 0;
    double vite = 0.00;
    double variable1 = -0.4;
    double variable2 = -0.4;

    sfSoundBuffer* sound;
    sfSound* sound_Y;

    sfVideoMode mode = {1350, 700};
    sfRenderWindow* window;
    sfEvent event;

    sfTexture* filet;
    sfSprite* filetS;
    sfVector2f positionfil = {675, 0};

    sfTexture* texture2;
    sfSprite* sprite2;
    sfVector2f position2j = {1200, 350};

    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f position = {50, 50};

    sfTexture* coterhaute;
    sfSprite* coterhaut;
    sfVector2f position1 = {0, 2};

    sfTexture* coterbase;
    sfSprite* coterbas;
    sfVector2f position2 = {0, 683};

    sfTexture* balle;
    sfSprite* balleS;
    sfVector2f posballe = {600, 350};

    sfVector2i mouse;
    sfMouseButton button = sfMouseLeft;

    sfKeyCode lhaut = 25;
    sfKeyCode lbas = 18;

    sfKeyCode fhaut = sfKeyUp;
    sfKeyCode fbas = sfKeyDown;

    sound = sfSoundBuffer_createFromFile("ENY.ogg");
    sound_Y = sfSound_create();
    sfSound_setBuffer(sound_Y, sound);

    filet = sfTexture_createFromFile("filet.png", NULL);
    filetS = sfSprite_create();
    sfSprite_setTexture(filetS, filet, sfTrue);
    sfSprite_setPosition(filetS, positionfil); 

    texture2 = sfTexture_createFromFile("blanc20100.png", NULL);
    sprite2 = sfSprite_create();
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfSprite_setPosition(sprite2, position2j);

    texture = sfTexture_createFromFile("blanc20100.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);

    coterhaute = sfTexture_createFromFile("COTERHAUT.png", NULL);
    coterhaut = sfSprite_create();
    sfSprite_setTexture(coterhaut, coterhaute, sfTrue);
    sfSprite_setPosition(coterhaut, position1);

    coterbase = sfTexture_createFromFile("COTERHAUT.png", NULL);
    coterbas = sfSprite_create();
    sfSprite_setTexture(coterbas, coterbase, sfTrue);
    sfSprite_setPosition(coterbas, position2);

    balle = sfTexture_createFromFile("balleee.png", NULL);
    balleS = sfSprite_create();
    sfSprite_setTexture(balleS, balle, sfTrue);
    sfSprite_setPosition(balleS, posballe);

    window = sfRenderWindow_create(mode, "PONG 2D", sfResize | sfClose, NULL);


    //sfSound_play(sound_Y);
    //fenetre :
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        if (sfKeyboard_isKeyPressed(fhaut) && position2j.y > 5)
            position2j.y -= 0.8;
        if (sfKeyboard_isKeyPressed(fbas) && position2j.y < 595)
            position2j.y += 0.8;

        if (sfKeyboard_isKeyPressed(lhaut) && position.y > 5)
            position.y -= 0.8;
        if (sfKeyboard_isKeyPressed(lbas) && position.y < 595)
            position.y += 0.8;
        
        posballe.x = posballe.x + variable1;
        posballe.y = posballe.y + variable2;

        if (posballe.y < 5 && variable1 < 0) {
            variable1 = (-0.4 - vite);
            variable2 = (0.4 + vite);
        }
        if (posballe.y > 610 && variable1 < 0) {
            variable1 = (-0.4 - vite);
            variable2 = (-0.4 - vite);
        }
        if (posballe.x < position.x && variable2 < 0 && (posballe.y >= position.y - 50 && posballe.y <= position.y + 100)) {
            variable1 = (0.4 + vite);
            variable2 = (-0.4 - vite);
            vite += 0.05;
        }
        if (posballe.x < position.x && variable2 > 0 && (posballe.y >= position.y - 50 && posballe.y <= position.y + 100)) {         
            variable1 = (0.4 + vite);
            variable2 = (0.4 + vite);
            vite += 0.05;
        }
        if (posballe.x < position.x - 10) {
            score1++;
            vite = 0;
            variable1 = 0.4;
            variable2 = 0.4;
            posballe.x = 600;
            posballe.y = 350;
            if (score1 == 5)
                sfRenderWindow_close(window);
        }
        
        if (posballe.y < 5 && variable1 > 0) {
            variable1 = (0.4 + vite);
            variable2 = (0.4 + vite);
        }
        if (posballe.y > 610 && variable1 > 0) {
            variable1 = (0.4 + vite);
            variable2 = (-0.4 - vite);
        }
        if (posballe.x > position2j.x - 40 && variable2 < 0 && (posballe.y >= position2j.y - 50 && posballe.y <= position2j.y + 100)) {
            variable1 = (-0.4 - vite);
            variable2 = (-0.4 - vite);
            vite += 0.05;
        }
        if (posballe.x > position2j.x - 40 && variable2 > 0 && (posballe.y >= position2j.y - 50 && posballe.y <= position2j.y + 100)) {
            variable1 = (-0.4 - vite);
            variable2 = (0.4 + vite);
            vite += 0.05;
        }
        if (posballe.x > position2j.x + 10) {
            score2++;
            vite = 0;
            variable1 = 0.4;
            variable2 = 0.4;
            posballe.x = 600;
            posballe.y = 350;
            if (score2 == 5)
                sfRenderWindow_close(window);
        }
        sfSprite_setPosition(balleS, posballe);
        sfSprite_setPosition(sprite, position);
        sfSprite_setPosition(sprite2, position2j);
        sfSprite_setPosition(filetS, positionfil);
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite2, NULL);
        sfRenderWindow_drawSprite(window, coterhaut, NULL);
        sfRenderWindow_drawSprite(window, coterbas, NULL);
        sfRenderWindow_drawSprite(window, balleS, NULL);
        sfRenderWindow_drawSprite(window, filetS, NULL);
        sfRenderWindow_display(window);   
    }
    sfSound_stop(sound_Y);
    sfSound_destroy(sound_Y);
    sfSoundBuffer_destroy(sound);
    sfRenderWindow_close(window);
    printf("joueur 1 a fais %d et joueur 2 a fais %d\n", score2, score1);
    if (score1 > score2)
        printf("joueur 1 a gagné !!! Bravo le sang\n");
    else
         printf("joueur 1 a gagné !!! Bravo le sang\n");
}