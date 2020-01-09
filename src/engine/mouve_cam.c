/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <SFML/Graphics.h>
#include "main_struct.h"
#include "my_world.h"

int mouve_cam(void *pg, int dir)
{
    if (dir == 1 || dir == 2)
        ((program_t *)pg)->world->info->translate.x += (dir == 1) ? -8 : 8;
    if (dir == 3 || dir == 4)
        ((program_t *)pg)->world->info->translate.y += (dir == 3) ? -8 : 8;
    refresh_iso_cords(((program_t *)pg)->world);
    return (0);
}

int zoom_cam(void *pg, int direction)
{
    if ((direction == 1 && ((program_t *)pg)->world->info->zoom < 300)
        || (direction == 2 && ((program_t *)pg)->world->info->zoom > 10))
        ((program_t *)pg)->world->info->zoom += (direction == 1) ? 2 : -2;
    refresh_iso_cords(((program_t *)pg)->world);
    return (0);
}

int change_mode(void *pg, int direction)
{
    int actual = ((program_t *)pg)->world->info->mode_modif;
    int new = (actual > 2) ? 1 : actual + 1;

    if (direction == 1)
        ((program_t *)pg)->world->info->mode_modif = new;
    if (direction == 2)
        ((program_t *)pg)->world->info->mode_modif = 4;
    ((program_t *)pg)->event.key.code = sfKeyUnknown;
    refresh_iso_cords(((program_t *)pg)->world);
    return (0);
}

int rotate(void *pg, int direction)
{
    ((program_t *)pg)->world->info->rot +=
    (((program_t *)pg)->world->info->rot > 200) ? -300 : 100;
    ((program_t *)pg)->event.key.code = sfKeyUnknown;
    return (direction);
}
