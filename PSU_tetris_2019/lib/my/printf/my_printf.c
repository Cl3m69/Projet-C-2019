/*
** EPITECH PROJECT, 2019
** my_print
** File description:
** Printf function
*/

#include "../../../include/my.h"

int my_printf(char *txt, ... )
{
    int i = 0;
    va_list aq;

    va_start(aq, txt);
    while (txt[i] != 0) {
        if (txt[i] == '%') {
            i++;
            i = flag_required(i, txt, aq);
        }
        else {
            my_putchar(txt[i]);
            i++;
        }
    }
    va_end(aq);
    return 0;
}