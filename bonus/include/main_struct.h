/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef STRUCT_G
#define STRUCT_G

#include <SFML/Graphics.h>
#include "world/struct_world.h"

typedef struct program_s
{
    sfRenderWindow *wd;
    world_t *world;
} program_t;

#endif
