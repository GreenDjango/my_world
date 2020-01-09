/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef STRUCT_WORLD
#define STRUCT_WORLD

#include <SFML/Graphics.h>
#include <SFML/System/Vector3.h>//sfVector3f
#include <SFML/System/Vector2.h>//sfVector2f
#include <SFML/System/Types.h>//Clock

typedef struct face_s
{
    sfConvexShape *convex;
    float depth_z;
    int *point;
    int draw;
} face_t;

typedef struct block_s
{
    sfVector3f *pts;
    face_t *face;
    int *od;
} block_t;

typedef struct world_s
{
    block_t *map;
} world_t;

#endif
