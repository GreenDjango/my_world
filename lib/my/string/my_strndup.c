/*
** EPITECH PROJECT, 2018
** my_strndup
** File description:
** return a pointer to duplicate a part of string
*/

#include <stdlib.h>
#include "../include/my_string.h"

char *my_strndup(char const *src, int size)
{
    char *str;

    str = malloc(sizeof(char) * (size + 1));
    if (str == NULL)
        return (NULL);
    my_strncpy(str, src, size);
    return (str);
}
