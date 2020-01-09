/*
** EPITECH PROJECT, 2018
** my_free
** File description:
** secure free
*/

#include <stdarg.h>
#include <stdlib.h>

int my_free(int nb, ...)
{
    va_list list;
    void *tmp;
    int i = -1;

    va_start(list, nb);
    while (++i < nb)
        if ((tmp = va_arg(list, void *)) != NULL)
            free(tmp);
    va_end(list);
    return (0);
}
