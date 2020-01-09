/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef ENGINE
#define ENGINE

#include "main_struct.h"
#include "world/struct_world.h"

void draw_world(sfRenderWindow *wd, world_t *world);
sfVector2f get_2d(sfVector3f point);
block_t generate_block(sfVector3f pos, sfVector3f size);
void trans_rotation_block(char axe, block_t *block, float angle);
void change_height(float change, world_t *world, sfVector2i *emp);

#endif
