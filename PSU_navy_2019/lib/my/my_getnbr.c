/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** getnbr
*/

int my_getnbr(char *str)
{
    int i = 0;
    int n = 0;
    long resultat = 0;

    while (str[i] >= 48 && str[i] <= 57) {
        resultat = resultat * 10 + (str[i] - '0');
        i++;
        n++;
    }
    if (!(str[i] >= 48 && str[i] <= 57) && str[i] != 0)
        return -1;
    return resultat;
}
