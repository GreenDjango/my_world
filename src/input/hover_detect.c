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
my_click_t *hover_init(void)
{
    my_click_t *hov = malloc(sizeof(my_click_t) * (NB_ZONE_HOVER + 1));

    hov[0] = add_zone(10, get_pts(925, 15, 225, 70), &show_help, 0);
    return (hov);
}

int check_hover(void *pg, my_click_t *clk, inp_info_t *info, sfVector2i *mouse)
{
    int i = -1;

    while (++i < NB_ZONE_HOVER)
        if (clk[i].state == info->state
            && clk[i].emp[0].x <= mouse->x && mouse->x <= clk[i].emp[1].x
            && clk[i].emp[0].y <= mouse->y && mouse->y <= clk[i].emp[1].y)
            return (clk[i].pfunc(pg, clk[i].setting));
    return (0);
}
