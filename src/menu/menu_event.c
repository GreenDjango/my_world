/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>//Clock
#include <stdlib.h>
#include "main_struct.h"
#include "config.h"
#include "menu.h"
#include "setup.h"
#include "my_world.h"
#include "lib/my_string.h"

int pause_music(void *gp, int setting)
{
    program_t *pg = (program_t *)gp;
    sfColor color = sfSprite_getColor(pg->tex->spr_menu_sound);
    sfColor color1 = {255, 255, 255, 255};

    if (pg->tim.sound_button == 0) {
        if (color.r == 255 && color.g == 255 && color.b == 255) {
            sfMusic_pause(pg->msc->msc1);
            sfSprite_setColor(pg->tex->spr_menu_sound, sfRed);
        } else {
            sfMusic_play(pg->msc->msc1);
            sfSprite_setColor(pg->tex->spr_menu_sound, color1);
        }
        sfMusic_play(pg->msc->snd1);
        pg->tim.sound_button = 20;
    }
    return (setting);
}

void button_event2(program_t *pg, int setting, char *str)
{
    if ((setting == 4 || setting == 5) && pg->info.mod != 2) {
        sfMusic_play(pg->msc->snd1);
        pg->tim.save_map = 0;
        pg->tim.sound_button = 0;
        pg->tim.slide_preview = 0;
        pg->tim.fade_black = 0;
    }
    if (setting == 4 && pg->info.mod == 1 && my_strlen(str =
    pg->map_file[pg->info.mod-1][pg->info.menu]) < 23) {
        pg->font->new_name[0] = '\0';
        my_strncpy(pg->font->new_name, str, my_strlen(str)-7);
        setup_iso_block(pg, pg->world,
        pg->map_file[pg->info.mod-1][pg->info.menu]);
    }
    if (setting == 5 && pg->tim.map_range < 1 && pg->info.mod != 2) {
        pg->tim.map_range = 15;
        pg->info.state = 1;
        pg->tim.sound_button = 0;
    }
}

int button_event(void *gp, int setting)
{
    program_t *pg = (program_t *)gp;

    if (pg->info.menu == 0 && setting < 3) {
        if (pg->tim.fade_screen == 0 && (setting == 0 || setting == 1)) {
            pg->tim.fade_screen = 1;
            pg->info.menu = 1;
            pg->info.mod = setting+1;
        }
        if (setting == 2)
            sfRenderWindow_close(pg->wd);
        sfMusic_play(pg->msc->snd1);
    } else if (setting == 3 && pg->tim.fade_screen == 0 && pg->info.menu) {
        pg->info.menu = 0;
        pg->tim.fade_screen = 1;
        sfTexture_updateFromRenderWindow(pg->tex->tex_screen, pg->wd, 0, 0);
        sfMusic_play(pg->msc->snd1);
    }
    button_event2(pg, setting, NULL);
    return (0);
}

int slide_map_preview(void *gp, int setting)
{
    program_t *pg = (program_t *)gp;
    sfFloatRect rec = sfSprite_getGlobalBounds(pg->tex->spr_menu_map);
    sfVector2f pos = {rec.left, rec.top};

    if (pg->info.menu && !pg->tim.slide_preview) {
        if (setting == 0 && pg->info.menu < pg->map_file[pg->info.mod-1][0][0])
            pg->tim.slide_preview = -1;
        if (setting == 1 && pg->info.menu > 1)
            pg->tim.slide_preview = 1;
    } else if (pg->tim.slide_preview && setting != 0 && setting != 1) {
        pg->tim.slide_preview += (pg->tim.slide_preview > 0) ? 1 : -1;
        pos.x += (pg->tim.slide_preview > 0) ? 50 : -50;
        pg->info.menu += (setting == 2) ? 1 : 0;
        pg->info.menu -= (setting == 3) ? 1 : 0;
        pos.x += (setting == 2) ? 1000 : 0;
        pos.x -= (setting == 3) ? 1000 : 0;
        pg->tim.slide_preview = (setting >= 2) ? 0 : pg->tim.slide_preview;
    }
    sfSprite_setPosition(pg->tex->spr_menu_map, pos);
    return (0);
}
