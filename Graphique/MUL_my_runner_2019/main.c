/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** main
*/

#include "include/setup.h"

void destroy(m_t *st)
{
    sfSound_stop(st->setup.sound);
    sfSound_destroy(st->setup.sound);
    sfSoundBuffer_destroy(st->setup.soundbuf);
}

void analyse_event(m_t *st)
{
    st->setup.button = sfMouseLeft;
    if (st->setup.event.type == sfEvtClosed)
        sfRenderWindow_close(st->setup.window);
}

void open_game(m_t *st, list_t *liste)
{
    switch (st->setup.game)
    {
    case 0:
        menu_game(st, liste);
        break;
    case 1:
        play_game(st, liste);
        break;
    case 2:
        my_pause(st, liste);
        break;
    case 3:
        sfRenderWindow_close(st->setup.window);
        break;
    case 4:
        game_over(st, liste);
        break;
    }
}

void main2(m_t *st, list_t *liste)
{
    menu_up(st);
    while (sfRenderWindow_isOpen(st->setup.window)) {
        while (sfRenderWindow_pollEvent(st->setup.window, &(st->setup.event)))
            analyse_event(st);
        sfRenderWindow_clear(st->setup.window, sfBlack);
        open_game(st, liste);
        sfRenderWindow_display(st->setup.window);
    }
}

int main(int ac, char **av)
{
    m_t st;
    list_t *list;
    int error = 0;

    st.setup.ac = ac;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0) {
        flag();
        return 0;
    }
    if (ac == 2 && av[1][0] != '-')
        error = check_map(&st, av[1]);
    if (error == 84)
        return (write(2, "Bad map !\n", 10));
    init_up(&st);
    sfSound_play(st.setup.sound);
    if (ac == 2)
        list = init_ob(&st);
    main2(&st, list);
    destroy(&st);
    return 0;
}