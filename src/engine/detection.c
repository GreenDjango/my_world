/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include "main_struct.h"
#include "engine/world.h"
#include "config.h"
#include "tools.h"
#include "my_world.h"

int check_polygone(sfVector3f *pts, sfVector2i mouse, int size)
{
    int i = -1;
    int pos = 0;
    int neg = 0;
    int i2;
    int d;

    while (++i < size) {
        i2 = (i < size - 1) ? i + 1 : 0;
        d = (mouse.x - pts[i].x) * (pts[i2].y - pts[i].y) - (mouse.y - pts[i].y)
        * (pts[i2].x - pts[i].x);
        pos += (d > 0) ? 1 : 0;
        neg += (d < 0) ? 1 : 0;
        if (pos > 0 && neg > 0)
            return (0);
    }
    return (1);
}

int check_detection_trinagle(sfVector3f *pts, sfVector2i mouse)
{
    sfVector3f t1[3] = {pts[1], pts[0], pts[2]};
    sfVector3f t2[3] = {pts[0], pts[3], pts[2]};

    if (check_polygone(t1, mouse, 3) == 1 || check_polygone(t2, mouse, 3) == 1)
        return (1);
    return (0);
}

int check_detection_point(engine_t *world, sfVector3f *pts, sfVector2i *emp)
{
    int i = -1;
    sfVector2f emp2;

    while (++i < 4)
        if (emp->x - 10 < pts[i].x && pts[i].x < emp->x + 10
        && emp->y - 10 < pts[i].y && pts[i].y < emp->y + 10) {
            emp2.x = (-pts[i].x) + 5;
            emp2.y = (-pts[i].y) + 5;
            sfCircleShape_setRadius(world->cursor, 5);
            sfCircleShape_setOrigin(world->cursor, emp2);
            return (1);
        }
    return (0);
}

void refresh_tx(block_t *map, int **tx, int *alive)
{
    int i = -1;
    sfVector2i emp = {0, 0};

    while (++i < NB_MAX_BLOCK)
        if (alive[i]) {
            emp = map[i].map_emp;
            map[i].face[0].texture = tx[emp.y][emp.x];
        }
}

void check_hover_iso(program_t *pg, block_t *map, sfVector2i *mouse, int *alive)
{
    int i = NB_MAX_BLOCK;
    int **tx = pg->world->iso->texture;

    refresh_tx(map, tx, alive);
    while (pg->world->info->mode_modif > 1 && --i >= 0)
        if (alive[i] && check_detection_trinagle(map[i].pts, *mouse)) {
            refresh_hover_face(map[i].pts, pg->world->hover
            , pg->world->info->mode_modif, pg->world->info->rot);
            sfCircleShape_setRadius(pg->world->cursor, 0);
            pg->world->info->pos_hover = i;
            return;
        }
    sfVertexArray_clear(pg->world->hover);
    while (pg->world->info->mode_modif == 1 && --i >= 0)
        if (alive[i] && check_detection_point(pg->world, map[i].pts, mouse))
            return;
    sfCircleShape_setRadius(pg->world->cursor, 0);
}
