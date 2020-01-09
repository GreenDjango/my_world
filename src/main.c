/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include "lib/my_string.h"
#include "my_world.h"

int my_print_usage(void)
{
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return (my_print_usage());
    return (my_world());
}
