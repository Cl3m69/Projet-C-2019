/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    long i;
    i = nb;

    if (i < 0)
    {
        i = i * -1;
        my_putchar('-');
    }
    if (i > 9)
    {
        my_put_nbr(i / 10);
    }
    my_putchar('0' + i % 10);
    return (0);
}
