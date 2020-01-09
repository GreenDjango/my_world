/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

sfVector2i *get_pts(int x1, int y1, int x2, int y2)
{
    sfVector2i *out = malloc(sizeof(sfVector2i) * 2);

    out[0].x = x1;
    out[0].y = y1;
    out[1].x = x1 + x2;
    out[1].y = y1 + y2;
    return (out);
}

sfVector2i get_vector2i(int y, int x)
{
    sfVector2i vector = {y, x};

    return (vector);
}

sfVector2f get_vector2f(float y, float x)
{
    sfVector2f vector = {y, x};

    return (vector);
}

sfVector2f get_2pts(sfVector3f in)
{
    sfVector2f out = {in.x, in.y};

    return (out);
}
