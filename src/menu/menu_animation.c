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

void fade_windows_zoom(program_t *pg)
{
    sfColor color = {255, 255, 255, 255 - (pg->tim.fade_screen - 50)*1.7};
    sfVector2f size = {pg->tim.fade_screen/100.0+1,
        pg->tim.fade_screen/100.0+1};

    if (pg->tim.fade_screen < 50)
        color.a = 255;
    if (pg->tim.fade_screen == 1) {
        pg->tim.fade_screen += 1;
        if (pg->info.menu != 0)
            sfTexture_updateFromRenderWindow(pg->tex->tex_screen, pg->wd, 0, 0);
    }
    sfSprite_setScale(pg->tex->spr_screen, size);
    sfSprite_setColor(pg->tex->spr_screen, color);
    sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_screen, NULL);
}

void fade_windows_black(program_t *pg)
{
    sfColor color = {0, 0, 0, pg->tim.fade_black};

    sfRectangleShape_setFillColor(pg->tex->rec_color, color);
    sfRenderWindow_drawRectangleShape(pg->wd, pg->tex->rec_color, NULL);
}

void fade_button(program_t *pg)
{
    sfColor color;

    for (int y = 0; y < MENU_OPT; y++) {
        color = sfRectangleShape_getFillColor(pg->tex->rec_menu_button[y]);
        if (color.r > 210) {
            color.r -= 1;
            color.g -= 1;
            color.b -= 1;
            color.a -= 1;
            sfRectangleShape_setFillColor(pg->tex->rec_menu_button[y], color);
        }
    }
}
