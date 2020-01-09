/*
** EPITECH PROJECT, 2018
** my_put_error
** File description:
** error_manage
*/

#include <unistd.h>
#include "../include/my_string.h"

int my_put_error(char *msg, int return_line)
{
    write(2, msg, my_strlen(msg));
    if (return_line == 2)
        write(2, ": ", 2);
    if (return_line == 1)
        write(2, "\n", 1);
    return (84);
}
