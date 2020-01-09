/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef MY_MENU
#define MY_MENU

text_t *create_font(void);
texture_t *create_texture(void);
music_game_t *create_music(void);
void fade_windows_zoom(program_t *pg);
void fade_windows_black(program_t *pg);
void fade_button(program_t *pg);
void print_range(program_t *pg);
void print_menu_map_preview(program_t *pg);
void print_menu_text_button(program_t *pg);
void print_menu_button(program_t *pg);
void print_menu(program_t *pg);
void print_fps(program_t *pg);

#endif
