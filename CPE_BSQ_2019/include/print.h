/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** my
*/

#ifndef PRINT_H_
#define PRINT_H_

#include <stdarg.h>

int my_convert_base(int nb, char *base);
char *my_Hex(int i, unsigned int nb, char *base, char c);
int flag_required_cut2(int i, char *txt, va_list aq);
int flag_required_cut(int i, char *txt, va_list aq);
int flag_required(int i, char *txt, va_list aq);
char *my_octale_base(unsigned int nb, char c);
char *my_binary_base(unsigned int nb);
int my_printf(char *txt, ... );
void my_putstr_S(char *str);

#endif