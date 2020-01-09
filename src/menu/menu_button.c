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
#include "menu.h"

void print_menu_map_preview(program_t *pg)
{
    sfFloatRect rec = sfSprite_getGlobalBounds(pg->tex->spr_menu_map);
    sfVector2f pos = {rec.left, rec.top};

    for (int i = 0; i < 5; i++) {
        if ((pg->info.menu-2)+i > 0 && (pg->info.menu-2)+i <=
        pg->map_file[pg->info.mod-1][0][0]) {
            sfSprite_setPosition(pg->tex->spr_menu_map, pos);
            sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_menu_map, NULL);
            sfText_setString(pg->font->text_menu,
            pg->map_file[pg->info.mod-1][(pg->info.menu-2)+i]);
            pos.y += rec.height;
            sfText_setPosition(pg->font->text_menu, pos);
            pos.y -= rec.height;
            sfRenderWindow_drawText(pg->wd, pg->font->text_menu, NULL);
        }
        pos.x += 1000;
    }
    pos.x = rec.left;
    sfSprite_setPosition(pg->tex->spr_menu_map, pos);
}

void print_menu_text_button(program_t *pg)
{
    char *str[MENU_OPT] = {MENU_STR};
    sfFloatRect rec[2] = {{0, 0, 0, 0}, {0, 0, 0, 0}};
    sfVector2f pos = {0, 0};
    int tmp = 0;

    if (pg->info.menu && pg->tim.fade_screen != 1)
        tmp = MENU_OPT/2;
    for (int y = tmp; y < (MENU_OPT/2)+tmp; y++) {
        sfText_setString(pg->font->text_menu, str[y]);
        rec[1] = sfText_getGlobalBounds(pg->font->text_menu);
        rec[0] = sfRectangleShape_getGlobalBounds(pg->tex->rec_menu_button[y]);
        pos.x = rec[0].left + (rec[0].width/2) - (rec[1].width/2) - 5;
        pos.y = rec[0].top + (rec[0].height/2) - (rec[1].height) + 5;
        sfText_setPosition(pg->font->text_menu, pos);
        sfRenderWindow_drawText(pg->wd, pg->font->text_menu, NULL);
    }
}

void print_menu_button(program_t *pg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(pg->wd);
    sfFloatRect rec = {0, 0, 0, 0};
    sfColor color = {255, 255, 255, 255};
    int tmp = 0;

    if (pg->info.menu && pg->tim.fade_screen != 1)
        tmp = MENU_OPT/2;
    for (int y = tmp; y < (MENU_OPT/2)+tmp; y++) {
        rec = sfRectangleShape_getGlobalBounds(pg->tex->rec_menu_button[y]);
        if (mouse.x >= rec.left && mouse.x <= rec.left+rec.width && mouse.y >=
        rec.top && mouse.y <= rec.top+rec.height) {
            sfRectangleShape_setFillColor(pg->tex->rec_menu_button[y], color);
        }
        sfRenderWindow_drawRectangleShape(pg->wd, pg->tex->rec_menu_button[y],
        NULL);
    }
}
