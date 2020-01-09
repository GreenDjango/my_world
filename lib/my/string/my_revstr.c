/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse order of string
*/

#include <stdlib.h>
#include "../include/my_string.h"

char *my_revstr(char *str)
{
    char *temp = my_strdup(str);
    int size = my_strlen(str);
    int i = -1;

    while (++i < size)
        str[i] = temp[size - i - 1];
    if (temp)
        free(temp);
    return (str);
}
