/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include "main_struct.h"
#include "lib/my_system.h"
#include "setup.h"

void free_iso_block(engine_t *world, int stop)
{
    int i = -1;

    while (++i < NB_MAX_BLOCK && world->alive_blc[i] != 1 && stop == 0);
    if (i >= NB_MAX_BLOCK || stop != 0)
        return;
    world->alive_blc[i] = 0;
    sfVertexArray_destroy(world->rendu[i].face[0].polygone);
    sfVertexArray_destroy(world->rendu[i].face[0].line);
    my_free(2, world->rendu[i].pts, world->rendu[i].face[0]);
}

void free_name_map(program_t *pg)
{
    int tmp = 0;

    for (int y = 0; y < 2; y++) {
        tmp = pg->map_file[y][0][0];
        for (int i = 0; i < tmp; i++)
            free(pg->map_file[y][i]);
        free(pg->map_file[y]);
    }
    free(pg->map_file);
    pg->map_file = find_map();
}

void free_iso_mode(program_t *pg)
{
    int i = -1;
    engine_t *world = pg->world;

    pg->info.state = 0;
    for (int a = 0; a < world->info->map_size.y; a++)
        my_free(2, world->iso->map_iso[a], world->iso->texture[a]);
    my_free(1, world->iso->map_iso, world->iso->texture, world->iso);
    while (++i < (world->info->map_size.y - 1))
        for (int a = 0; a < (world->info->map_size.x - 1); a++)
            free_iso_block(world, ((world->info->map_size.y - 2 == i
            && world->info->map_size.x - 2 == a) ? 1 : 0));
    free_name_map(pg);
    setup_value(pg);
}
