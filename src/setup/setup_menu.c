/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderTexture.h>//sfRenderTexture
#include "config.h"
#include "lib/mtg_window.h"//lib
#include "main_struct.h"

void create_screen_saver(texture_t *all_tex)
{
    sfVector2f origin = {WINX/2, WINY/2};
    sfFloatRect rec = sfSprite_getGlobalBounds(all_tex->spr_menu_map);
    sfVector2f pos = {WINX/2, WINY/2};

    all_tex->tex_screen = sfTexture_create(WINX, WINY);
    all_tex->spr_screen = sfSprite_create();
    sfSprite_setTexture(all_tex->spr_screen, all_tex->tex_screen, sfFalse);
    sfSprite_setOrigin(all_tex->spr_screen, origin);
    sfSprite_setPosition(all_tex->spr_screen, origin);
    pos.x -= (rec.width/2) + 2000;
    pos.y -= rec.height/2;
    sfSprite_setPosition(all_tex->spr_menu_map, pos);
    pos.x = 1810;
    pos.y = 980;
    sfSprite_setPosition(all_tex->spr_menu_sound, pos);
}

void create_rectangle2(texture_t *all, sfVector2f size)
{
    sfVector2f pos[] = {{10, 8}, {(WINX/2)-size.x-40, (WINY/2)+340},
        {(WINX/2)+40, (WINY/2)+340}, {60, 60}};
    sfColor color = {230, 230, 230, 255};

    sfRectangleShape_setPosition(all->rec_menu_button[MENU_OPT/2], pos[0]);
    sfRectangleShape_setPosition(all->rec_menu_button[MENU_OPT/2+1], pos[1]);
    sfRectangleShape_setPosition(all->rec_menu_button[MENU_OPT/2+2], pos[2]);
    all->rec_tex = sfRectangleShape_create();
    sfRectangleShape_setSize(all->rec_tex, pos[3]);
    sfRectangleShape_setOutlineColor(all->rec_tex, color);
}

void create_rectangle(texture_t *all, sfTexture *tex[NB_TEXTURE])
{
    sfVector2f size = {323, 75};
    sfVector2f pos = {(WINX/2)-(size.x/2), (WINY/2)-(size.y+100)};
    sfColor color = {210, 210, 210, 210};

    for (int i = 0; i < MENU_OPT; i++) {
        all->rec_menu_button[i] = sfRectangleShape_create();
        sfRectangleShape_setTexture(all->rec_menu_button[i], tex[2], sfTrue);
        sfRectangleShape_setSize(all->rec_menu_button[i], size);
        sfRectangleShape_setFillColor(all->rec_menu_button[i], color);
        sfRectangleShape_setPosition(all->rec_menu_button[i], pos);
        pos.y += 110;
    }
    create_rectangle2(all, size);
    all->rec_color = sfRectangleShape_create();
    size.x = WINX;
    size.y = WINY;
    sfRectangleShape_setSize(all->rec_color, size);
}
