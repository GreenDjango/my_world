/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include "engine/world.h"
#include "config.h"
#include "setup.h"

info_t *setup_info(void)
{
    info_t *info = malloc(sizeof(info_t));

    info->souris_button = 0;
    info->emp.x = 0;
    info->emp.y = 0;
    info->translate.y = START_TRANSLATE_Y;
    info->translate.x = START_TRANSLATE_X;
    info->zoom = START_ZOOM;
    info->map_size.x = 0;
    info->map_size.y = 0;
    info->mode_modif = 1;
    info->key = 0;
    info->pos_hover = 0;
    info->is_translate = 0;
    info->is_zoom = 0;
    info->is_x_value = 0;
    info->rot = 0;
    return (info);
}

engine_t *setup_world(void)
{
    engine_t *world = malloc(sizeof(engine_t));
    sfVector2f emp = {0, 0};
    int i = -1;

    world->mode = -1;
    world->alive_blc = malloc(sizeof(int) * NB_MAX_BLOCK);
    while (++i < NB_MAX_BLOCK)
        world->alive_blc[i] = 0;
    world->iso = NULL;
    world->map_3d = NULL;
    world->rendu = malloc(sizeof(block_t) * NB_MAX_BLOCK);
    world->info = setup_info();
    world->cursor = sfCircleShape_create();
    world->refresh = 0;
    world->tx_blc = malloc(sizeof(sfTexture *) * (NB_TEX_BLOCK));
    world->hover = sfVertexArray_create();
    load_block_textures(world->tx_blc);
    sfCircleShape_setRadius(world->cursor, 5);
    sfCircleShape_setOrigin(world->cursor, emp);
    return (world);
}
