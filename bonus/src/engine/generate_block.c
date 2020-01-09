/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include "main_struct.h"
#include "world/struct_world.h"

sfVector3f create_point(int x, int y, int z)
{
    sfVector3f point = {x, y, z};

    return (point);
}

int *generate_ref_point(int one, int two, int tree, int four)
{
    int *out = malloc(sizeof(int) * 4);

    out[0] = one;
    out[1] = two;
    out[2] = tree;
    out[3] = four;
    return (out);
}

sfVector3f *generate_cords_vertexs(sfVector3f pos, sfVector3f size)
{
    sfVector3f *emp = malloc(sizeof(sfVector3f) * (8));
    float randz = (rand() % 50) / 25;

    emp[0] = pos;
    emp[1] = create_point(pos.x + size.x, pos.y, pos.z);
    emp[2] = create_point(pos.x + size.x, pos.y + size.y, pos.z);
    emp[3] = create_point(pos.x, pos.y + size.y, pos.z);
    emp[4] = create_point(pos.x, pos.y, pos.z + size.z + randz);
    emp[5] = create_point(pos.x + size.x, pos.y, pos.z + size.z + randz);
    emp[6] = create_point(pos.x + size.x, pos.y + size.y,
    pos.z + size.z + randz);
    emp[7] = create_point(pos.x, pos.y + size.y, pos.z + size.z + randz);
    return (emp);
}

void extra(block_t *block)
{
    block->od = malloc(sizeof(int *) * 6);
    for (int a = 0; a < 6; a++)
        block->od[a] = a;
    sfConvexShape_setFillColor(block->face[0].convex, sfRed);
    sfConvexShape_setFillColor(block->face[1].convex, sfGreen);
    sfConvexShape_setFillColor(block->face[2].convex, sfBlue);
    sfConvexShape_setFillColor(block->face[3].convex, sfYellow);
    sfConvexShape_setFillColor(block->face[4].convex, sfMagenta);
    sfConvexShape_setFillColor(block->face[5].convex, sfCyan);
}

block_t generate_block(sfVector3f pos, sfVector3f size)
{
    int ref[] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 5, 4
        , 2, 3, 7, 6, 1, 2, 6, 5, 0, 3, 7, 4};
    block_t block;
    int emp = 0;
    int i = -1;

    block.pts = generate_cords_vertexs(pos, size);
    block.face = malloc(sizeof(face_t) * 6);
    while (++i < 6) {
        block.face[i].convex = sfConvexShape_create();
        sfConvexShape_setPointCount(block.face[i].convex, 4);
        block.face[i].depth_z = 0.0;
        block.face[i].draw = 1;
        block.face[i].point = generate_ref_point(ref[0 + emp], ref[1 + emp],
        ref[2 + emp], ref[3 + emp]);
        emp += 4;
    }
    extra(&block);
    return (block);
}
