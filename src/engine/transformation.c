/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <math.h>
#include <SFML/System/Vector2.h>
#include "main_struct.h"
#include "config.h"

sfVector3f trans_iso(info_t *cam, int y, int x, int z)
{
    sfVector3f pos = {0, 0, z};

    pos.x = ANGLE_X * (x * cam->zoom) - ANGLE_X * (y * cam->zoom);
    pos.y = ANGLE_Y * (y * cam->zoom) + ANGLE_Y * (x * cam->zoom)
    - (z * cam->zoom / 50);
    pos.x += cam->translate.x;
    pos.y += cam->translate.y;
    return (pos);
}

sfVector2f rot(sfVector2f *p, int rota)
{
    sfTransform trans = sfTransform_Identity;
    float midX = 256 / 2.0;
    float midY = 256 / 2.0;
    float rot = 90.0 * rota;
    sfVector2f res = {0, 0};

    sfTransform_rotateWithCenter(&trans, rot, midX, midY);
    res = sfTransform_transformPoint(&trans, *p);
    return (res);
}
