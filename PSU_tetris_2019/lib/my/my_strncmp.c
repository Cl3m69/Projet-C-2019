/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** 
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s2[i] == '\0' && s1[i] == '\0')
        return (0);
    while (s2[i] == s1[i] && i != n - 1)
    {
        i++;
    }
    return (s1[i] - s2[i]);
}
