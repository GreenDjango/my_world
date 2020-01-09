/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** return a pointer to duplicate string
*/

#include <stdlib.h>
#include "../include/my_string.h"

char *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return (NULL);
    my_strcpy(str, src);
    return (str);
}
