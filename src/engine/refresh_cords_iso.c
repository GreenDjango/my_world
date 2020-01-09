/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <SFML/System/Vector2.h>
#include "config.h"//       NB_MAX_BLOCK
#include "my_world.h"
#include "main_struct.h"//  engine_t
#include "engine/world.h"
#include "tools.h"

void refresh_hover_face(sfVector3f *pts, sfVertexArray *vt, int mode, int tx)
{
    sfVector2f t[] = {get_vector2f(0, 0), get_vector2f(256, 0)
        , get_vector2f(256, 256), get_vector2f(0, 256)};
    sfColor cl = { 255, (mode == 3) ? 100 : 255, (mode == 3) ? 100 : 255, 100};
    sfColor cl2 = {225, 225, 225, 180};
    sfVertex v[4] = {
        {get_2pts(pts[1]), cl, rot(&t[1], tx / 100)},
        {get_2pts(pts[0]), cl, rot(&t[0], tx / 100)},
        {get_2pts(pts[2]), cl, rot(&t[2], tx / 100)},
        {get_2pts(pts[3]), cl, rot(&t[3], tx / 100)}
    };
    for (int i = 0; i < 4 && mode == 4; i++)
        v[i].color = cl2;
    sfVertexArray_clear(vt);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(vt, v[i]);
    sfVertexArray_setPrimitiveType(vt, sfTrianglesStrip);
}

void set_tx_iso_block(block_t *bl, int tx, sfColor cl)
{
    sfVector2f t[] = {get_vector2f(0, 0), get_vector2f(256, 0)
        , get_vector2f(256, 256), get_vector2f(0, 256)};
    sfVertex v[4] = {
        {get_2pts(bl->pts[1]), cl, rot(&t[1], tx / 100)},
        {get_2pts(bl->pts[0]), cl, rot(&t[0], tx / 100)},
        {get_2pts(bl->pts[2]), cl, rot(&t[2], tx / 100)},
        {get_2pts(bl->pts[3]), cl, rot(&t[3], tx / 100)}
    };
    sfVertexArray_clear(bl->face[0].polygone);
    sfVertexArray_clear(bl->face[0].line);
    sfVertexArray_append(bl->face[0].line, v[1]);
    for (int a = 1; a < 4; a++)
        sfVertexArray_append(bl->face[0].line, v[(a == 1) ? 0 : a]);
    for (int i = 0; i < 4; i++) {
        v[i].color = sfWhite;
        sfVertexArray_append(bl->face[0].polygone, v[i]);
    }
    sfVertexArray_setPrimitiveType(bl->face[0].polygone, sfTrianglesStrip);
    sfVertexArray_setPrimitiveType(bl->face[0].line, sfLinesStrip);
    bl->face[0].texture = tx;
}

void apply_extra(engine_t *world, int y, int x, int emp)
{
    int **map = world->iso->map_iso;

    world->alive_blc[emp] = 1;
    world->rendu[emp].map_emp.x = x;
    world->rendu[emp].map_emp.y = y;
    world->rendu[emp].pts[0] = trans_iso(world->info, y, x, map[y][x]);
    world->rendu[emp].pts[1] = trans_iso(world->info, y, x + 1, map[y][x + 1]);
    world->rendu[emp].pts[2] = trans_iso(world->info, y + 1, x + 1
    , map[y + 1][x + 1]);
    world->rendu[emp].pts[3] = trans_iso(world->info, y + 1, x, map[y + 1][x]);
}

void apply_iso_cords(engine_t *world, sfVector2i *size, int y, int x)
{
    int emp = (y * (size->y - 1)) + x;
    int **tx = world->iso->texture;
    sfColor cl = {240, 240, 240, 255};

    if (emp >= NB_MAX_BLOCK || !world->alive_blc[emp] || (size->y - 2 == y
        && size->x - 2 == x))
        return;
    apply_extra(world, y, x, emp);
    if (size->y - 2 == y) {
        world->rendu[emp].pts[2] = trans_iso(world->info, y, x + 1, SIDE_BLOCK);
        world->rendu[emp].pts[3] = trans_iso(world->info, y, x, SIDE_BLOCK);
    } else if (size->x - 2 == x) {
        world->rendu[emp].pts[1] = trans_iso(world->info, y, x, SIDE_BLOCK);
        world->rendu[emp].pts[2] = trans_iso(world->info, y + 1, x, SIDE_BLOCK);
    }
    set_tx_iso_block(&world->rendu[emp], tx[y][x], cl);
}

void refresh_iso_cords(engine_t *world)
{
    int i = -1;
    sfVector2i size = world->info->map_size;

    while (++i < (size.y - 1))
        for (int a = 0; a < (size.x - 1); a++)
            apply_iso_cords(world, &size, i, a);
}
