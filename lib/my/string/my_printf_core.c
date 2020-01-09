/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf_core
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../include/my_string.h"
#include "../include/my_printf.h"

void milking_flag(char flag, va_list *list)
{
    int i = -1;
    const flag_t f_tab[] =
    {
        {&flag_d, 'd'},
        {&flag_c, 'c'},
        {&flag_s, 's'},
        {NULL, -1},
    };

    while (f_tab[++i].key != -1)
        if (f_tab[i].key == flag)
            f_tab[i].pfunc(list);
}

int my_printf(char *s, ...)
{
    int i = -1;
    va_list list;

    va_start(list, s);
    while (s[++i] != '\0') {
        if (s[i] == '%' && s[i + 1] != '\0')
            milking_flag(s[++i], &list);
        else
            my_putchar(s[i]);
    }
    return (0);
}
