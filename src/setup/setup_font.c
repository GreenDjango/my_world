/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "main_struct.h"
#include "setup.h"

void set_style_font(text_t *all_font)
{
    sfText_setFont(all_font->text_fps, all_font->font_andro);
    sfText_setFont(all_font->text_menu, all_font->font_andro);
    sfText_setFont(all_font->text_map, all_font->font_andro);
    sfText_setFont(all_font->text_info, all_font->font_andro);
    sfText_setCharacterSize(all_font->text_map, 90);
    sfText_setCharacterSize(all_font->text_fps, 70);
    sfText_setCharacterSize(all_font->text_menu, 50);
    sfText_setCharacterSize(all_font->text_info, 35);
    sfText_setString(all_font->text_info, GAME_INFO);
    sfText_setStyle(all_font->text_menu, sfTextItalic);
}

text_t *create_font(void)
{
    text_t *all_font = malloc(sizeof(text_t));
    sfVector2f tmp = {1820, -20};

    all_font->font_andro = sfFont_createFromFile("data/font/andromeda.ttf");
    all_font->text_fps = sfText_create();
    all_font->text_menu = sfText_create();
    all_font->text_map = sfText_create();
    all_font->text_info = sfText_create();
    set_style_font(all_font);
    all_font->new_name[0] = '\0';
    sfText_setPosition(all_font->text_fps, tmp);
    return (all_font);
}