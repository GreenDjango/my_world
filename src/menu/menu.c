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

void print_menu_text_title(program_t *pg)
{
    sfVector2f pos = {0, 0};
    sfFloatRect rec;

    sfText_setString(pg->font->text_map, "Select Map");
    if (pg->info.mod == 2)
        sfText_setString(pg->font->text_map,
        "The 3D program is on the bonus folder");
    rec = sfText_getGlobalBounds(pg->font->text_map);
    pos.x = (WINX/2) - (rec.width/2);
    pos.y = (WINY/2) - (rec.height/2) - 400;
    sfText_setPosition(pg->font->text_map, pos);
    sfRenderWindow_drawText(pg->wd, pg->font->text_map, NULL);
}

void menu_clock2(program_t *pg)
{
    pg->tim.counter.y += 0.1;
    if (pg->tim.counter.y >= WINY)
        pg->tim.counter.y = 0;
    if (pg->tim.fade_screen > 1)
        pg->tim.fade_screen += 8;
    if (pg->tim.fade_screen > 200)
        pg->tim.fade_screen = 0;
    if (pg->tim.fade_black)
        pg->tim.fade_black -= 3;
    if (pg->tim.fade_black < 3)
        pg->tim.fade_black = 0;
    if (pg->tim.slide_preview >= 20)
        slide_map_preview(pg, 3);
    if (pg->tim.slide_preview <= -20)
        slide_map_preview(pg, 2);
    if (pg->tim.slide_preview)
        slide_map_preview(pg, -1);
    if (pg->tim.sound_button > 0)
        pg->tim.sound_button -= 1;
}

void menu_clock(program_t *pg)
{
    int tmp = sfClock_getElapsedTime(pg->tim.clock_star).microseconds;

    while (tmp > 16667) {
        tmp -= 16667;
        sfClock_restart(pg->tim.clock_star);
        fade_button(pg);
        menu_clock2(pg);
    }
}

void print_menu_background(program_t *pg)
{
    pg->tim.counter.x = 0;
    sfSprite_setPosition(pg->tex->spr_menu_star, pg->tim.counter);
    sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_menu_star, NULL);
    pg->tim.counter.y -= WINY;
    sfSprite_setPosition(pg->tex->spr_menu_star, pg->tim.counter);
    sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_menu_star, NULL);
    pg->tim.counter.y += WINY;
    if (!pg->info.menu || pg->tim.fade_screen == 1)
        sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_menu_name, NULL);
    sfRenderWindow_drawSprite(pg->wd, pg->tex->spr_menu_sound, NULL);
}

//Print for the menu of the game
void print_menu(program_t *pg)
{
    menu_clock(pg);
    print_menu_background(pg);
    print_menu_button(pg);
    print_menu_text_button(pg);
    if (pg->info.menu && pg->tim.fade_screen != 1) {
        print_menu_map_preview(pg);
        print_menu_text_title(pg);
    }
    if (pg->tim.map_range > 0)
        print_range(pg);
    if (pg->tim.fade_screen)
        fade_windows_zoom(pg);
    if (pg->tim.fade_black)
        fade_windows_black(pg);
}
