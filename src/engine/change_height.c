/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include "main_struct.h"//  engine_t
#include "config.h"//   NB_MAX_BLOCK
#include "my_world.h"
#include "tools.h"

int extra_check_iso(int out, program_t *pg, block_t rendu, sfVector2i *emp)
{
    int tex = (pg->tim.chose_tex < 0)
    ? -(pg->tim.chose_tex) -1 : pg->tim.chose_tex - 1;

    if (pg->world->info->mode_modif == 4 && (check_polygone(rendu.pts, *emp, 4)
    || check_polygone(rendu.pts, *emp, 3)) && (out = 1)) {
        if (pg->tim.chose_tex > 0 && (1580 > emp->x || emp->x > 1900
            || 154 > emp->y || emp->y > 990))
            pg->world->iso->texture[rendu.map_emp.y][rendu.map_emp.x] =
            (tex % 100) + pg->world->info->rot;
        else if (pg->tim.chose_tex < 0)
            pg->world->iso->texture[rendu.map_emp.y][rendu.map_emp.x] =
            (tex % 100) + pg->world->info->rot;
    }
    return (out);
}

int check_block_iso(program_t *pg, block_t rendu, sfVector2i *emp, int *stat)
{
    engine_t *world = pg->world;
    int ref[] = {0, 0, 0, 1, 1, 1, 1, 0};
    int out = 0;
    int i = -1;

    while (stat[0] == 1 && ++i < 4)
        if (emp->x - 10 < rendu.pts[i].x && rendu.pts[i].x < emp->x + 10
        && emp->y - 10 < rendu.pts[i].y && rendu.pts[i].y < emp->y + 10
        && (out = 1)) {
            world->info->emp.y = rendu.map_emp.y + ref[i * 2];
            world->info->emp.x = rendu.map_emp.x + ref[(i * 2) + 1];
            world->info->souris_button = 1;
        }
    if ((stat[0] == 2 || stat[0] == 3) && (check_polygone(rendu.pts, *emp, 4)
    || check_polygone(rendu.pts, *emp, 3)) && (out = 1)) {
        world->info->souris_button = stat[0];
        world->info->emp.y = rendu.map_emp.y;
        world->info->emp.x = rendu.map_emp.x;
    }
    return (extra_check_iso(out, pg, rendu, emp));
}

void reset_height(engine_t *world, program_t *pg, sfVector2i des, int *ref)
{
    int small = 0;
    int **map = world->iso->map_iso;

    if (world->info->souris_button == 3 && pg->info.button == 0)
        for (int a = 0; a < 4; a++)
            map[des.y + ref[a * 2]][des.x + ref[(a * 2) + 1]]=0;
    if (world->info->souris_button == 3 && pg->info.button == 1) {
        small = map[des.y + ref[0]][des.x + ref[1]];
        for (int a = 0; a < 4; a++)
            small = (map[des.y + ref[a * 2]][des.x + ref[(a * 2) + 1]] > small)
            ? map[des.y + ref[a * 2]][des.x + ref[(a * 2) + 1]] : small;
        for (int a = 0; a < 4; a++)
            map[des.y + ref[a * 2]][des.x + ref[(a * 2) + 1]]=small;
    }
}

void change_height_iso(int mode, int va, program_t *pg, sfVector2i *emp)
{
    int ref[] = {0, 0, 0, 1, 1, 1, 1, 0};
    engine_t *world = pg->world;
    sfVector2i des = world->info->emp;
    int stat[] = {mode, va};
    int i = NB_MAX_BLOCK;
    int result = 0;

    if (world->info->souris_button == 1)
        world->iso->map_iso[des.y][des.x] += va;
    if (world->info->souris_button == 2)
        for (int a = 0; a < 4; a++)
            world->iso->map_iso[des.y + ref[a * 2]][des.x + ref[(a * 2) + 1]]
            += va;
    reset_height(world, pg, des, ref);
    while (!world->info->souris_button && --i >= 0 && !result)
        if (world->alive_blc[i])
            result = check_block_iso(pg, world->rendu[i], emp, stat);
}
