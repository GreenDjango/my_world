/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include "main_struct.h"
#include "setup.h"
#include "input.h"
#include "menu.h"
#include "my_world.h"

void clean_cam(sfEvent *event)
{
    if (event->key.code != sfKeyP && sfKeyboard_isKeyPressed(sfKeyP))
        event->key.code = sfKeyP;
    if (event->key.code != sfKeyM && sfKeyboard_isKeyPressed(sfKeyM))
        event->key.code = sfKeyM;
    if (event->key.code != sfKeyLeft && sfKeyboard_isKeyPressed(sfKeyLeft))
        event->key.code = sfKeyLeft;
    if (event->key.code != sfKeyRight && sfKeyboard_isKeyPressed(sfKeyRight))
        event->key.code = sfKeyRight;
    if (event->key.code != sfKeyUp && sfKeyboard_isKeyPressed(sfKeyUp))
        event->key.code = sfKeyUp;
    if (event->key.code != sfKeyDown && sfKeyboard_isKeyPressed(sfKeyDown))
        event->key.code = sfKeyDown;
    if (!sfKeyboard_isKeyPressed(sfKeyP) && !sfKeyboard_isKeyPressed(sfKeyM) &&
        !sfKeyboard_isKeyPressed(sfKeyLeft) && !sfKeyboard_isKeyPressed(sfKeyUp)
        && !sfKeyboard_isKeyPressed(sfKeyDown) && event->key.code != sfKeyC &&
        !sfKeyboard_isKeyPressed(sfKeyRight) && event->key.code != sfKeyR
        && event->key.code != sfKeyT)
        event->key.code = sfKeyUnknown;
}

void extra_event(sfEvent *event, program_t *pg, sfVector2i *pos)
{
    check_key(pg, pg->input.key, event->key.code, pg->info.state + 10);
    if (pg->info.state == 10)
        check_key(pg, pg->input.key, event->key.code, pg->info.state);
    if (pg->info.state == 10)
        check_hover_iso(pg, pg->world->rendu, pos, pg->world->alive_blc);
    if (!sfMouse_isButtonPressed(sfMouseLeft)
        && !sfMouse_isButtonPressed(sfMouseRight))
        pg->world->info->souris_button = 0;
    check_hover((void *)pg, pg->input.hover_clk, &pg->info, pos);
}

void input_event(sfEvent *event, program_t *pg)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(pg->wd);

    while (sfRenderWindow_pollEvent(pg->wd, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(pg->wd);
        if (pg->info.state == 10)
            clean_cam(event);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pg->info.button = 0;
        check_zone((void *)pg, pg->input.clk, &pg->info, &pos);
        if (pg->info.state == 10 && (pg->world->refresh = 1) == 1)
            change_height_iso(pg->world->info->mode_modif, 2, pg, &pos);
    } else if (sfMouse_isButtonPressed(sfMouseRight)) {
        pg->info.button = 1;
        check_zone((void *)pg, pg->input.clk, &pg->info, &pos);
        if (pg->info.state == 10 && (pg->world->refresh = 1) == 1)
            change_height_iso(pg->world->info->mode_modif, -2, pg, &pos);
    }
    extra_event(event, pg, &pos);
}

int my_world(void)
{
    program_t *pg = setup_program();

    sfRenderWindow_setVerticalSyncEnabled(pg->wd, sfTrue);
    while (sfRenderWindow_isOpen(pg->wd)) {
        input_event(&(pg->event), pg);
        sfRenderWindow_clear(pg->wd, sfBlack);
        if (pg->info.state == 0 || pg->info.state == 1)
            print_menu(pg);
        else if (pg->info.state == 10)
            main_engine_iso_mode(pg);
        print_fps(pg);
        sfRenderWindow_display(pg->wd);
    }
    free_program(pg);
    return (0);
}
