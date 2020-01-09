/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef MY_SETUP
#define MY_SETUP

#include "main_struct.h"

program_t *setup_program(void);
void create_screen_saver(texture_t *all_tex);
void create_rectangle(texture_t *all, sfTexture **tex);
char ***find_map(void);
void setup_value(program_t *pg);
engine_t *setup_world(void);
void load_block_textures(sfTexture **tx);
void setup_iso_block(program_t *pg, engine_t *world, char *pathfile);

#endif
