/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <SFML/System/Vector2.h>

sfVector2i *get_pts(int x1, int y1, int x2, int y2)
{
    sfVector2i *out = malloc(sizeof(sfVector2i) * 2);

    out[0].x = x1;
    out[0].y = y1;
    out[1].x = x1 + x2;
    out[1].y = y1 + y2;
    return (out);
}
