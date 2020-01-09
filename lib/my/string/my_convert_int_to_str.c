/*
** EPITECH PROJECT, 2018
** my_convert_int_to_str
** File description:
** convert (int) to (char *)
*/

#include <stdlib.h>
#include "../include/my_string.h"

char *my_convert_int_to_str(long int nb)
{
    int size = my_nbrlen(nb);
    char *result = malloc(sizeof(char) * (size + 2));
    int calc;
    int i = -1;
    int a = 0;

    if (nb < 0) {
        result[a] = '-'; a++;
    }
    while (++i < size) {
        calc = (nb < 0) ? ((nb % 10) * -1) : nb % 10;
        result[(size - 1 - i) + a] = (calc + '0');
        nb /= 10;
    }
    result[i + a] = '\0';
    return (result);
}
