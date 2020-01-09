/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include "main_struct.h"

void setup_value(program_t *pg)
{
    pg->tim.frame_fps = 0;
    pg->tim.counter.x = 0;
    pg->tim.counter.y = 0;
    pg->tim.fade_screen = 0;
    pg->tim.fade_black = 255;
    pg->tim.slide_preview = 0;
    pg->tim.sound_button = 0;
    pg->tim.map_range = 0;
    pg->tim.save_map = 0;
    pg->tim.fade_toolbar = -1630;
    pg->tim.chose_tex = -1;
    pg->info.menu = 0;
    pg->info.mod = 0;
}
