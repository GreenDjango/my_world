/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** display a char
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
