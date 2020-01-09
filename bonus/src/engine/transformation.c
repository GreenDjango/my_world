/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <math.h>
#include <SFML/System/Vector3.h>// sfVector3f
#include "world/struct_world.h"

sfVector2f get_2d(sfVector3f point)
{
    sfVector2f result;

    result.x = 1920/2 + (point.x * 50);
    result.y = 1080/2 + (point.y * 50);
    return (result);
}

void trans_rotation_x(sfVector3f *point, float angle)
{
    sfVector3f tmp = *point;

    point->y = (cos(angle) * point->y) - (sin(angle) * point->z);
    point->z = (sin(angle) * tmp.y) + (cos(angle) * tmp.z);
}

void trans_rotation_y(sfVector3f *point, float angle)
{
    sfVector3f tmp = *point;

    point->x = (cos(angle) * point->x) + (sin(angle) * point->z);
    point->z = -(sin(angle) * tmp.x) + (cos(angle) * tmp.z);
}

void trans_rotation_z(sfVector3f *point, float angle)
{
    sfVector3f tmp = *point;

    point->x = (cos(angle) * point->x) - (sin(angle) * point->y);
    point->y = (sin(angle) * tmp.x) + (cos(angle) * tmp.y);
}

void trans_rotation_block(char axe, block_t *block, float angle)
{
    float rad_angle = angle * M_PI/180;
    int i = -1;

    while (++i < 8) {
        if (axe == 'x')
            trans_rotation_x(&(block->pts[i]), rad_angle);
        if (axe == 'y')
            trans_rotation_y(&(block->pts[i]), rad_angle);
        if (axe == 'z')
            trans_rotation_z(&(block->pts[i]), rad_angle);
    }
}
