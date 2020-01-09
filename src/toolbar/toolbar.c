/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>//Clock
#include "main_struct.h"
#include "config.h"
#include "engine/toolbar.h"
#include "my_world.h"

int slide_tool(void *gp, int setting)
{
    program_t *pg = (program_t *)gp;

    if (pg->info.state == 10) {
        if (!pg->tim.fade_toolbar && setting == 1
        && pg->tim.slide_preview != 2) {
            pg->tim.slide_preview = 2;
            sfMusic_play(pg->msc->snd1);
        } else if (pg->tim.fade_toolbar == -1630 && setting == 2
        && pg->tim.slide_preview != 1) {
            pg->tim.slide_preview = 1;
            sfMusic_play(pg->msc->snd1);
        }
    }
    return (setting);
}

void print_toolbar(program_t *pg)
{
    sfVector2f pos = {pg->tim.fade_toolbar, 0};

    sfSprite_setPosition(pg->tex->spr_toolbar, pos);
    sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_toolbar, NULL);
    if (pg->tim.chose_tex > 0)
        print_chose_tex(pg);
    if (pg->tim.fade_black == 1) {
        sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_msg, NULL);
        sfRenderWindow_drawText(pg->wd, pg->font->text_info, NULL);
        pg->tim.fade_black = 0;
    }
    if (pg->tim.save_map)
        show_save_message(pg);
}

void check_toolbar_value(program_t *pg)
{
    pg->tim.counter.y += 0.1;
    if (pg->tim.counter.y >= WINY)
        pg->tim.counter.y = 0;
    if (pg->tim.slide_preview == 1)
        pg->tim.fade_toolbar += -(0.15*pg->tim.fade_toolbar) + 5;
    if (pg->tim.slide_preview == 2)
        pg->tim.fade_toolbar += (0.2*pg->tim.fade_toolbar) - 5;
    if (pg->tim.fade_toolbar >= 0)
        pg->tim.fade_toolbar = 0;
    if (pg->tim.fade_toolbar <= -1630)
        pg->tim.fade_toolbar = -1630;
    if (pg->tim.sound_button)
        pg->tim.sound_button--;
    if (pg->tim.save_map)
        pg->tim.save_map--;
}

void print_game_background(program_t *pg)
{
    int tmp = sfClock_getElapsedTime(pg->tim.clock_star).microseconds;

    pg->tim.counter.x = 0;
    sfSprite_setPosition(pg->tex->spr_menu_star, pg->tim.counter);
    sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_menu_star, NULL);
    pg->tim.counter.y -= WINY;
    sfSprite_setPosition(pg->tex->spr_menu_star, pg->tim.counter);
    sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_menu_star, NULL);
    pg->tim.counter.y += WINY;
    while (tmp > 33333) {
        tmp -= 33333;
        sfClock_restart(pg->tim.clock_star);
        check_toolbar_value(pg);
    }
}
