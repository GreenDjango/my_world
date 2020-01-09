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

int exit_game(void *gp, int setting)
{
    program_t *pg = (program_t *)gp;

    if (!pg->tim.save_map) {
        sfMusic_play(pg->msc->snd1);
        if (setting == 1) {
            pg->tim.save_map = 30;
            save_map_iso(pg->world->iso, &pg->world->info->map_size,
            pg->font->new_name);
        } else if (setting == 2) {
            pg->font->new_name[0] = '\0';
            free_iso_mode(pg);
        }
    }
    return (setting);
}

int texture_event(void *gp, int setting)
{
    program_t *pg = (program_t *)gp;

    if (pg->tim.sound_button == 0 && !setting && !pg->tim.fade_toolbar) {
        pg->tim.chose_tex = -pg->tim.chose_tex;
        pg->tim.sound_button = 10;
        sfMusic_play(pg->msc->snd1);
    }
    if (setting && pg->tim.chose_tex > 0)
        pg->tim.chose_tex = setting;
    return (setting);
}

void print_chose_tex(program_t *pg)
{
    sfVector2f pos = {1910, 90};

    for (int i = 0; i < NB_TEX_BLOCK; i++) {
        if (i % 12 == 0) {
            pos.x -= 80;
            pos.y = 90;
        }
        pos.y += 70;
        if (i + 1 == pg->tim.chose_tex)
            sfRectangleShape_setOutlineThickness(pg->tex->rec_tex, 5.0);
        sfRectangleShape_setTexture(pg->tex->rec_tex, pg->world->tx_blc[i],
        sfFalse);
        sfRectangleShape_setPosition(pg->tex->rec_tex, pos);
        sfRenderWindow_drawRectangleShape(pg->wd, pg->tex->rec_tex, NULL);
        if (i + 1 == pg->tim.chose_tex)
            sfRectangleShape_setOutlineThickness(pg->tex->rec_tex, 0.0);
    }
}

void show_save_message(program_t *pg)
{
    sfVector2f pos = {700, 500};

    sfText_setString(pg->font->text_map, "Map Saved...");
    sfText_setPosition(pg->font->text_map, pos);
    sfRenderWindow_drawText(pg->wd, pg->font->text_map, NULL);
}

int show_help(void *gp, int setting)
{
    program_t *pg = (program_t *)gp;
    sfVector2i tmp = sfMouse_getPositionRenderWindow(pg->wd);
    sfVector2f pos = {tmp.x, tmp.y};

    if (pg->tim.fade_toolbar == 0) {
        pg->tim.fade_black = 1;
        sfSprite_setPosition(pg->tex->spr_msg, pos);
        pos.x += 30;
        pos.y += 10;
        sfText_setPosition(pg->font->text_info, pos);
    }
    return (setting);
}