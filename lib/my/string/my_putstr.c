/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** writes out a string to the standard output
*/

#include <unistd.h>
#include "../include/my_string.h"

int my_putstr(char *str)
{
    int tt = my_strlen(str);

    write(1, str, tt);
    return (tt);
}
