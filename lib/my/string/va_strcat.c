/*
** EPITECH PROJECT, 2018
** my_strcat_stdarg
** File description:
** C-Project
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../include/my_string.h"

char *va_strcat(int nb, ...)
{
    char *result;
    va_list list;
    char *tmp;
    int i = -1;

    va_start(list, nb);
    result = va_arg(list, char *);
    while (++i < nb - 1) {
        tmp = result;
        result = my_strcat(result, va_arg(list, char *));
        if (i != 0 && tmp != NULL)
            free(tmp);
    }
    va_end(list);
    return (result);
}
