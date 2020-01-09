/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <SFML/Graphics.h>
#include "main_struct.h"
#include "engine/world.h"
#include "config.h"
#include "tools.h"

void draw_iso_face(sfRenderWindow *wd, block_t *blc, engine_t *world)
{
    sfRenderStates states;
    int i = -1;
    sfVector2f pos = sfCircleShape_getOrigin(world->cursor);
    int emp = blc->face[0].texture - ((blc->face[0].texture / 100) * 100);

    if (blc->face[0].texture != -1 && emp < NB_TEX_BLOCK)
        states.texture = world->tx_blc[emp];
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.shader = NULL;
    sfRenderWindow_drawVertexArray(wd, blc->face[0].polygone, &states);
    sfRenderWindow_drawVertexArray(wd, blc->face[0].line, NULL);
    while (++i < 4)
        if (blc->pts[i].x == (-pos.x) + 5 && blc->pts[i].y == (-pos.y) + 5)
            sfRenderWindow_drawCircleShape(wd, world->cursor, NULL);
}

void draw_map_iso(sfRenderWindow *wd, engine_t *world, program_t *pg)
{
    int i = -1;
    sfRenderStates states;

    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.shader = NULL;
    while (++i < NB_MAX_BLOCK) {
        if (world->alive_blc[i])
            draw_iso_face(wd, &world->rendu[i], world);
        if (i == world->info->pos_hover && pg->world->info->mode_modif != 4)
            sfRenderWindow_drawVertexArray(wd, world->hover, NULL);
        if (i == world->info->pos_hover && pg->world->info->mode_modif == 4) {
            states.texture = world->tx_blc[(pg->tim.chose_tex < 0)
            ? -(pg->tim.chose_tex) - 1: pg->tim.chose_tex - 1];
            sfRenderWindow_drawVertexArray(wd, world->hover, &states);
        }
    }
}
