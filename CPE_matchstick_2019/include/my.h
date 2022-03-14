/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

typedef struct stick
{
    char **map;
    char **tmp;
    int colonnes;
    int line;
    int matches;
    int linewr;
    int matcheswr;
    int game;
    int nb;
    int tmpnb;
    int loose;
} stick_t;

typedef struct ia
{
    char **map;
    int line;
    int match;
    struct ia *suivant;
}ia_t;

typedef struct liste
{
    struct ia *premier;
}list_t;

typedef struct M
{
    ia_t *ia;
    list_t *liste1;
    list_t *liste2;
    list_t *listewin;
    stick_t stick;
}struct_t;


int check_error(char **av, struct_t *stru);
int my_getnbr(char *str);
void init_struct(struct_t *stru);
void my_putstr(char *str);
void my_putchar(char c);
void my_display(struct_t *stru);
int get_match(struct_t *stru);
int get_line(struct_t *stru);
void change_map(struct_t *stru);
int my_put_nbr(int nb);
int my_game_cut(struct_t *stru);

void my_display_ia(struct_t *stru);
void ia_renforce(struct_t *stru);
void change_map_ia(struct_t *stru);
void get_lineia2(struct_t *stru);
void get_matchia2(struct_t *stru);
char **my_str_dup(struct_t *stru);
list_t *init_liste(void);
char **my_str_dup_ia(struct_t *stru);
void display_liste(struct_t *stru);
int get_matchiawin(struct_t *stru);
void init_map(struct_t *stru);
void init_struct2(struct_t *stru);
int my_put_nbr(int nb);
char **my_str_dup_iawin(struct_t *stru, ia_t *liste);
int add_elementliste1(struct_t *stru);
int add_elementliste2(struct_t *stru);
int get_matchiawin(struct_t *stru);
void push_list_win(struct_t *stru, int nb);
void add_elementlistewin1(struct_t *stru, ia_t *liste);
void my_ia1(struct_t *stru);
void my_ia2(struct_t *stru);
void get_lineia(struct_t *stru);
void get_matchia(struct_t *stru);
int get_iawin(struct_t *stru);
void check_win(struct_t *stru, int i);

#endif /* !MY_H_ */