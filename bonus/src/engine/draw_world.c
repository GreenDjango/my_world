/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "world/struct_world.h"
#include "world/engine.h"
#include "config.h"

void zbuffer_vertex_addition(int a, block_t *block)
{
    int i = -1;
    float result = 0;

    while (++i < 4)
        result = result + block->pts[block->face[a].point[i]].z;
    block->face[a].depth_z = result;
}

void zbuffer_sort_face(block_t *blc)
{
    int i = -1;
    face_t tmp;
    int tmp2;

    while (++i < 6)
        zbuffer_vertex_addition(i, blc);
    i = -1;
    while (++i < 5) {
        if (i != -1 && blc->face[i].depth_z > blc->face[i + 1].depth_z) {
            tmp = blc->face[i];
            tmp2 = blc->od[i];
            blc->od[i] = blc->od[i + 1];
            blc->od[i + 1] = tmp2;
            blc->face[i] = blc->face[i + 1];
            blc->face[i + 1] = tmp;
            i -= 2;
        }
    }
}

void zbuffer_sort_block(block_t *map)
{
    int i = -1;
    block_t tmp;

    while (++i < NB_BLOCK - 1) {
        if (i > -1 && map[i].pts[0].z > map[i + 1].pts[0].z) {
            tmp = map[i];
            map[i] = map[i + 1];
            map[i + 1] = tmp;
            i -= 2;
        }
    }
}

void draw_block(sfRenderWindow *wd, block_t *block)
{
    int i = -1;
    int a = -1;

    zbuffer_sort_face(block);
    while (++i < 6) {
        while (++a < 4)
            sfConvexShape_setPoint(block->face[i].convex, a
            , get_2d(block->pts[block->face[i].point[a]]));
        if (block->face[i].draw == 1)
            sfRenderWindow_drawConvexShape(wd, block->face[i].convex, NULL);
        a = -1;
    }
}

void draw_world(sfRenderWindow *wd, world_t *world)
{
    int i = -1;

    zbuffer_sort_block(world->map);
    while (++i < NB_BLOCK)
        draw_block(wd, &(world->map[i]));
}
