/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** rev
*/

void ft_swap(char *a, char *b)
{
    char temp = '0';

    temp = *a;
    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    int c = 0;
    int i = 0;

    while (str[c] != 0)
        c++;
    c = c - 1;
    while (i < c) {
        ft_swap(&str[i], &str[c]);
        i++;
        c--;
    }
    return str;
}
