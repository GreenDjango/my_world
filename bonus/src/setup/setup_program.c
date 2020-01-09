/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "world/struct_world.h"
#include "world/engine.h"
#include "main_struct.h"
#include "config.h"
#include "my_world.h"

void setup_block(block_t *map)
{
    int i = -1;

    while (++i < NB_BLOCK) {
        trans_rotation_block('z', &map[i], 45);
        trans_rotation_block('x', &map[i], 52);
    }
}

void create_block(world_t *world)
{
    sfVector3f size = {1, 1, 1};
    sfVector3f emp = {-5, -5, 0};
    sfVector3f tmp = emp;

    world->map = malloc(sizeof(block_t) * NB_BLOCK);
    for (int i = 0; i < 10; i++)
        for (int a = 0; a < 10; a++) {
            tmp.x = emp.x + i;
            tmp.y = emp.y + a;
            world->map[(i * 10) + a] = generate_block(tmp, size);
        }

}

program_t *setup_program(void)
{
    program_t *pg = malloc(sizeof(program_t));

    if (!pg)
        return (NULL);
    pg->wd = mtg_create_window(1920, 1080, "my_world", sfFullscreen);
    pg->world = malloc(sizeof(world_t));
    create_block(pg->world);
    setup_block(pg->world->map);
    return (pg);
}
