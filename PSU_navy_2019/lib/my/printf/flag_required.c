/*
** EPITECH PROJECT, 2019
** SU_my_printf_2019
** File description:
** flag_required
*/

#include "../../../include/my.h"

int flag_required_hashtag(char c, int i, char *txt, va_list aq)
{
    for (; txt[i] == '#'; i++);
    switch (txt[i])
    {
    case 'o':
        my_putstr(my_octale_base(va_arg(aq, unsigned int), c));
        break;
    case 'x':
        my_putstr(my_hex(0, va_arg(aq, unsigned int), "0123456789abcdef", c));
        break;
    case 'X':
        my_putstr(my_hex(0, va_arg(aq, unsigned int), "0123456789ABCDEF", c));
        break;
    default:
        flag_required(i, txt, aq);
    }
    return i;
}

int flag_required_cut2(int i, char *txt, va_list aq)
{
    char c = '0';

    switch (txt[i])
    {
    case 'p':
        my_putstr("0x");
        my_putstr(my_hex(0, va_arg(aq, int), "0123456789abcdef", txt[i]));
        break;
    case 'S':
        my_putstr_s(va_arg(aq, char *));
        break;
    case '#':
        c = '#';
        i = flag_required_hashtag(c, i, txt, aq);
        break;
    default:
        my_putchar(txt[i - 1]);
        my_putchar(txt[i]);
    }
    return i;
}

int flag_required_cut(int i, char *txt, va_list aq)
{
    switch (txt[i]) {
    case 'b':
        my_putstr(my_binary_base(va_arg(aq, unsigned int)));
        break;
    case 'o':
        my_putstr(my_octale_base(va_arg(aq, unsigned int), txt[i]));
        break;
    case 'x':
        my_putstr(my_hex(0, va_arg(aq, unsigned int), "0123456789abcdef", 'c'));
        break;
    case 'X':
        my_putstr(my_hex(0, va_arg(aq, unsigned int), "0123456789ABCDEF", 'c'));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        i = flag_required_cut2(i, txt, aq);
    }
    return i;
}

int flag_required(int i, char *txt, va_list aq)
{
    switch (txt[i])
    {
    case 'd': case 'i':
        my_put_nbr(va_arg(aq, int));
        break;
    case 's':
        my_putstr(va_arg(aq, char *));
        break;
    case 'c':
        my_putchar(va_arg(aq, int));
        break;
    default:
        i = flag_required_cut(i, txt, aq);
    }
    i++;
    return i;
}
