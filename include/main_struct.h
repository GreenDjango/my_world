/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef STRUCT_G
#define STRUCT_G

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "engine/world.h"
#include "input.h"

typedef struct my_time_s
{
    sfClock *clock_star;
    sfClock *clock_fps;
    int frame_fps;
    sfVector2f counter;
    int fade_black;
    int fade_screen;
    int slide_preview;
    int sound_button;
    int map_range;
    int fade_toolbar;
    int chose_tex;
    int save_map;
} my_time_t;

typedef struct music_game
{
    sfMusic *msc1;
    sfMusic *snd1;
}music_game_t;

typedef struct texture_s
{
    sfSprite *spr_menu_name;
    sfSprite *spr_menu_star;
    sfSprite *spr_menu_map;
    sfSprite *spr_menu_sound;
    sfSprite *spr_menu_range;
    sfSprite *spr_toolbar;
    sfSprite *spr_screen;
    sfSprite *spr_msg;
    sfTexture *tex_menu_name;
    sfTexture *tex_menu_star;
    sfTexture *tex_menu_map;
    sfTexture *tex_menu_sound;
    sfTexture *tex_menu_range;
    sfTexture *tex_menu_button;
    sfTexture *tex_toolbar;
    sfTexture *tex_msg;
    sfTexture *tex_screen;
    sfRectangleShape *rec_tex;
    sfRectangleShape *rec_color;
    sfRectangleShape **rec_menu_button;
} texture_t;

typedef struct text_s
{
    sfFont *font_andro;
    sfText *text_fps;
    sfText *text_menu;
    sfText *text_map;
    sfText *text_info;
    char new_name[15];
} text_t;

typedef struct program_s
{
    inp_info_t info;
    sfEvent event;
    sfRenderWindow *wd;
    input_t input;
    engine_t *world;
    my_time_t tim;
    text_t *font;
    char ***map_file;
    texture_t *tex;
    music_game_t *msc;
} program_t;

#endif
