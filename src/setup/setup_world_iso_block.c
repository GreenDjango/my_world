/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include "config.h"
#include "engine/world.h"
#include "tools.h"
#include "my_world.h"
#include "tools.h"

void allow_ressource_iso_block(engine_t *world, int stop)
{
    int i = -1;

    while (++i < NB_MAX_BLOCK && world->alive_blc[i] != 0 && stop == 0);
    if (i >= NB_MAX_BLOCK || stop != 0)
        return;
    world->alive_blc[i] = 1;
    world->rendu[i].map_emp = get_vector2i(-1, -1);
    world->rendu[i].face = malloc(sizeof(face_t));
    world->rendu[i].face[0].polygone = sfVertexArray_create();
    world->rendu[i].face[0].line = sfVertexArray_create();
    world->rendu[i].face[0].texture = 0;
    world->rendu[i].pts = malloc(sizeof(sfVector3f) * 4);
}

void setup_iso_block(program_t *pg, engine_t *world, char *pathfile)
{
    int i = -1;
    sfVector2i size;

    pg->info.state = 10;
    world->iso = read_map_iso(pathfile, &world->info->map_size);
    size = world->info->map_size;
    while (++i < (size.y - 1))
        for (int a = 0; a < (size.x - 1); a++)
            allow_ressource_iso_block(world, ((size.y - 2 == i
            && size.x - 2 == a) ? 1 : 0));
    refresh_iso_cords(world);
}
