/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include "main_struct.h"
#include "lib/my_system.h"
#include "setup.h"

void free_music(program_t *pg)
{
    sfMusic_stop(pg->msc->msc1);
    sfMusic_stop(pg->msc->snd1);
    sfMusic_destroy(pg->msc->msc1);
    sfMusic_destroy(pg->msc->snd1);
}

void free_program(program_t *pg)
{
    free_music(pg);
}
