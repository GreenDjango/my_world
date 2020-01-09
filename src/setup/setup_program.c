/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <dirent.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "lib/my_string.h"
#include "lib/mtg_window.h"
#include "main_struct.h"
#include "config.h"
#include "menu.h"
#include "input.h"
#include "setup.h"

input_t init_input_check(void *pg)
{
    input_t input;

    input.clk = click_init(pg);
    input.hover_clk = hover_init();
    input.key = key_init();
    return (input);
}

program_t *setup_program(void)
{
    program_t *pg = malloc(sizeof(program_t));
    const sfImage *logo_img = sfImage_createFromFile("data/logo.png");
    const sfUint8 *logo_pxl = sfImage_getPixelsPtr(logo_img);
    sfEvent event = {.key.code = sfKeyUnknown};
    inp_info_t info = {0, 0, 0, 0};

    pg->info = info;
    pg->wd = mtg_create_window(WINX, WINY, "my_world", sfFullscreen);
    sfRenderWindow_setIcon(pg->wd, 325, 325, logo_pxl);
    pg->font = create_font();
    pg->tex = create_texture();
    pg->msc = create_music();
    pg->map_file = find_map();
    pg->tim.clock_star = sfClock_create();
    pg->tim.clock_fps = sfClock_create();
    setup_value(pg);
    pg->input = init_input_check(pg);
    pg->event = event;
    pg->world = setup_world();
    return (pg);
}
