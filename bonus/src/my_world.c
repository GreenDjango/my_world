/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <SFML/Graphics.h>
#include "world/engine.h"
#include "main_struct.h"
#include "my_world.h"
#include "config.h"

sfVector2f get_2pts(sfVector3f in)
{
    sfVector2f out = {in.x, in.y};

    return (out);
}

void my_event_apply(sfEvent *event, program_t *pg)
{
    int i = -1;

    while (sfRenderWindow_pollEvent(pg->wd, event))
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(pg->wd);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        while (++i < NB_BLOCK)
            trans_rotation_block('x', &(pg->world->map[i]), 1);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        while (++i < NB_BLOCK)
            trans_rotation_block('y', &(pg->world->map[i]), 1);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        while (++i < NB_BLOCK)
            trans_rotation_block('x', &(pg->world->map[i]), -1);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        while (++i < NB_BLOCK)
            trans_rotation_block('y', &(pg->world->map[i]), -1);
}

int my_world(void)
{
    program_t *pg = setup_program();
    sfEvent event;

    sfRenderWindow_setFramerateLimit(pg->wd, 120);
    while (sfRenderWindow_isOpen(pg->wd)) {
        sfRenderWindow_clear(pg->wd, sfBlack);
        my_event_apply(&event, pg);
        draw_world(pg->wd, pg->world);
        sfRenderWindow_display(pg->wd);
    }
    return (0);
}
