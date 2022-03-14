/*
** EPITECH PROJECT, 2019
** librairie.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char *my_itoa(int nb);
int my_getnbr(char *str);
int my_strlen(char *str);
char *my_revstr(char *str);
void my_putstr(char *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strcmp(char *nb1, char *nb2);
char *my_strcpy(char *dest, char *src);

//myprintf

int my_convert_base(int nb, char *base);
char *my_hex(int i, unsigned int nb, char *base, char c);
int flag_required_cut2(int i, char *txt, va_list aq);
int flag_required_cut(int i, char *txt, va_list aq);
int flag_required(int i, char *txt, va_list aq);
char *my_octale_base(unsigned int nb, char c);
char *my_binary_base(unsigned int nb);
int my_printf(char *txt, ... );
void my_putstr_s(char *str);

#endif