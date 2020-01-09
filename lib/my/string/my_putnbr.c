/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display a number (int)
*/

#include <stdlib.h>
#include "../include/my_string.h"

int my_putnbr(int nb)
{
    char *str = my_convert_int_to_str(nb);

    if (str == NULL)
        return (84);
    my_putstr(str);
    free(str);
    return (0);
}
