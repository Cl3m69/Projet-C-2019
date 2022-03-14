/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>

int attack[5];

typedef struct map
{
    char **map;
    char **en_map;
    int check;
    int game;
    int user;
    int pid;
    int win;
    int en_win;
}map_t;


void print_help(void);
int check_error(int ac, char **av);
void create_map(char ***map);
void display_map(map_t *map);
int my_signal(map_t *map);
int first_user(map_t *map, char *pos);
int second_usr(map_t *map, char *pid, char *pos);
int init_game(map_t *map, int ac, char **av);
void quit_sig(int signo);
void received_pid(map_t *map, int i);
int receive_attack(void);
int is_touch(map_t *map);
int get_pos_boat(map_t *map, char *pos);
void send_pid(map_t *map);
void connecte_sig();
void send_attack(map_t *map, char *buf);
int check_attack(char buf[6]);
void receive_pos(void);
void nby_sig(int signo);
void nbx_sig(int signo);
void touch(int signo);
void missed(int signo);
void touch_or_missed(map_t *map, char *buf);
void change_map(map_t *map, int a);
void change_en_map(map_t *map, char *buf);
int is_win(map_t *map);
char *check_valid_file(char *buff);

#endif /* !NAVY_H_ */