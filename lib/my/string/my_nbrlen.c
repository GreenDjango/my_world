/*
** EPITECH PROJECT, 2018
** my_nblen
** File description:
** return lenth of nb
*/

int my_nbrlen(long int nb)
{
    int i = 0;

    while (++i > 0 && (nb > 9 || nb < -9))
        nb /= 10;
    return (i);
}
