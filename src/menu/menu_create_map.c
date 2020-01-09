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

void get_name_map(program_t *pg, int digit)
{
    int lenght = my_strlen(pg->font->new_name);

    if (((digit >= 'a' && digit <= 'z') || (digit >= 'A' && digit <= 'Z'))
    && lenght < 15 && !pg->tim.sound_button) {
        pg->font->new_name[lenght] = pg->event.text.unicode;
        pg->font->new_name[lenght+1] = '\0';
        pg->tim.sound_button = 5;
    }
    if (digit == 8 && lenght > 0 && !pg->tim.sound_button) {
        pg->font->new_name[lenght-1] = '\0';
        pg->tim.sound_button = 5;
    }
}

void print_range(program_t *pg)
{
    char *nb = my_convert_int_to_str(pg->tim.map_range);
    sfVector2f pos = {0, 350};
    sfFloatRect rec;

    get_name_map(pg, pg->event.text.unicode);
    pg->event.text.unicode = 0;
    sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_menu_range, NULL);
    sfText_setString(pg->font->text_menu, pg->font->new_name);
    rec = sfText_getGlobalBounds(pg->font->text_menu);
    pos.x = (WINX/2) - (rec.width/2);
    sfText_setPosition(pg->font->text_menu, pos);
    sfRenderWindow_drawText(pg->wd, pg->font->text_menu, NULL);
    sfText_setString(pg->font->text_map, nb);
    rec = sfText_getGlobalBounds(pg->font->text_map);
    pos.x = (WINX/2) - (rec.width/2);
    pos.y = 470;
    sfText_setPosition(pg->font->text_map, pos);
    sfRenderWindow_drawText(pg->wd, pg->font->text_map, NULL);
    free(nb);
}

int change_range(void *gp, int setting)
{
    program_t *pg = (program_t *)gp;

    if (!pg->tim.sound_button) {
        if (setting == 1 && pg->tim.map_range > 1)
            pg->tim.map_range--;
        if (setting == 2 && pg->tim.map_range < MAX_MAP_SIZE)
            pg->tim.map_range++;
        pg->tim.sound_button = 10;
    }
    if (setting == 3 && pg->font->new_name[0] != '\0') {
        create_new_map(pg->font->new_name, pg->tim.map_range);
        setup_iso_block(pg, pg->world,
        my_strcat(pg->font->new_name, ".legend"));
    } else if (setting == 4) {
        pg->info.state = 0;
        pg->tim.map_range = 0;
        pg->font->new_name[0] = '\0';
    }
    pg->event.key.code = sfKeyUnknown;
    return (0);
}