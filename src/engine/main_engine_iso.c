/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include "main_struct.h"
#include "my_world.h"
#include "engine/toolbar.h"

void main_engine_iso_mode(program_t *pg)
{
    print_game_background(pg);
    if (pg->world->refresh == 1 && !(pg->world->refresh = 0))
        refresh_iso_cords(pg->world);
    draw_map_iso(pg->wd, pg->world, pg);
    print_toolbar(pg);
}
