/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf_flags
*/

#include <stdarg.h>
#include "../include/my_string.h"

int flag_d(va_list *list)
{
    my_putnbr(va_arg(*list, int));
    return (0);
}

int flag_c(va_list *list)
{
    my_putchar((char)va_arg(*list, int));
    return (0);
}

int flag_s(va_list *list)
{
    my_putstr(va_arg(*list, char *));
    return (0);
}
