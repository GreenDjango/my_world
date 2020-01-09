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
#include "lib/my_string.h"
#include "config.h"

void print_fps(program_t *pg)
{
    char *str = NULL;

    pg->tim.frame_fps += 1;
    if (sfClock_getElapsedTime(pg->tim.clock_fps).microseconds > 1000000) {
        sfClock_restart(pg->tim.clock_fps);
        str = my_convert_int_to_str(pg->tim.frame_fps);
        sfText_setString(pg->font->text_fps, str);
        pg->tim.frame_fps = 0;
        free(str);
    }
    sfRenderWindow_drawText(pg->wd, pg->font->text_fps, NULL);
}