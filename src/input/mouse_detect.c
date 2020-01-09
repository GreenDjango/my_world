/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "main_struct.h"
#include "input.h"
#include "tools.h"
#include "config.h"

// ADD key detection                                              //1=Left, 2=R
// 1 - click[0] = add_zone(state, get_pts(px, py, sx, sy), &funct, buttonDetec);
//     you can add extra data input to called function : click[0].setting = ;
// 2 - increase NB_ZONE_CLICK (allowed ressourced)
// 3 - add the prototype of the called function in input.h
// (info) sx/sy = size x/y
void tex_click(my_click_t *ck, int index)
{
    sfVector2f pos = {1910, 90};

    for (int i = 0; i < NB_TEX_BLOCK; i++) {
        if (i % 12 == 0) {
            pos.x -= 80;
            pos.y = 90;
        }
        pos.y += 70;
        ck[index+i] = add_zone(10, get_pts(pos.x, pos.y, 60, 60)
        , &texture_event, 0);
        ck[index+i].setting = i+1;
    }
}

void more_click(my_click_t *ck)
{
    ck[MENU_OPT+3] = add_zone(10, get_pts(1650, 0, 100, 100), &slide_tool, 0);
    ck[MENU_OPT+3].setting = 1;
    ck[MENU_OPT+4] = add_zone(10, get_pts(0, 0, 120, 120), &slide_tool, 0);
    ck[MENU_OPT+4].setting = 2;
    ck[MENU_OPT+5] = add_zone(10, get_pts(185, 15, 225, 70), &texture_event, 0);
    ck[MENU_OPT+5].setting = 0;
    ck[MENU_OPT+6] = add_zone(10, get_pts(555, 15, 225, 70), &exit_game, 0);
    ck[MENU_OPT+6].setting = 1;
    ck[MENU_OPT+7] = add_zone(10, get_pts(1290, 15, 225, 70), &exit_game, 0);
    ck[MENU_OPT+7].setting = 2;
    ck[MENU_OPT+8] = add_zone(1, get_pts(800, 480, 160, 100), &change_range, 0);
    ck[MENU_OPT+8].setting = 1;
    ck[MENU_OPT+9] = add_zone(1, get_pts(961, 480, 160, 100), &change_range, 0);
    ck[MENU_OPT+9].setting = 2;
    tex_click(ck, MENU_OPT+10);
}

my_click_t *click_init(void *pgg)
{
    my_click_t *ck = malloc(sizeof(my_click_t) * (NB_ZONE_CLICK + 1));
    program_t *pg = (program_t *)pgg;
    sfFloatRect rec;

    for (int i = 0; i < MENU_OPT; i++) {
        rec = sfRectangleShape_getGlobalBounds(pg->tex->rec_menu_button[i]);
        ck[i] = add_zone(0, get_pts(rec.left, rec.top, rec.width, rec.height)
        , &button_event, 0);
        ck[i].setting = i;
    }
    ck[MENU_OPT] = add_zone(0, get_pts(1620, 360, 300, 360)
    , &slide_map_preview, 0);
    ck[MENU_OPT].setting = 0;
    ck[MENU_OPT+1] = add_zone(0, get_pts(0, 360, 300, 360)
    , &slide_map_preview, 0);
    ck[MENU_OPT+1].setting = 1;
    ck[MENU_OPT+2] = add_zone(0, get_pts(1810, 980, 70, 70), &pause_music, 0);
    more_click(ck);
    return (ck);
}

my_click_t add_zone(int st, sfVector2i *pt, int (*pf)(void *pg, int s), int bu)
{
    my_click_t click = {st, bu, pt, pf, 0};

    return (click);
}

int check_zone(void *pg, my_click_t *clk, inp_info_t *info, sfVector2i *mouse)
{
    int i = -1;

    while (++i < NB_ZONE_CLICK)
        if (clk[i].state == info->state && clk[i].button_used == info->button
            && clk[i].emp[0].x <= mouse->x && mouse->x <= clk[i].emp[1].x
            && clk[i].emp[0].y <= mouse->y && mouse->y <= clk[i].emp[1].y)
            return (clk[i].pfunc(pg, clk[i].setting));
    return (0);
}
