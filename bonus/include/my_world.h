/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef MY_WORLD
#define MY_WORLD

#include "main_struct.h"

int my_world(void);
program_t *setup_program(void);
sfRenderWindow *mtg_create_window(unsigned int wdh, unsigned int hgt,
char *name, sfUint32 style);
block_t generate_block(sfVector3f pos, sfVector3f size);

#endif
