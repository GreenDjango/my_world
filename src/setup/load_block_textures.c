/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "config.h"
#include "lib/my_string.h"

sfTexture *load_texture_from_file(char *pathfile)
{
    sfImage *load = sfImage_createFromFile(pathfile);
    sfTexture *my_texture = sfTexture_createFromImage(load, NULL);

    sfImage_destroy(load);
    return (my_texture);
}

void load_block_textures(sfTexture **tx)
{
    char *str = NULL;
    char *nb = NULL;

    for (int i = 0; i < NB_TEX_BLOCK; i++) {
        nb = my_convert_int_to_str(i+1);
        str = va_strcat(3, FOLDER_BLOCK, nb, ".png");
        tx[i] = load_texture_from_file(str);
        free(str);
        free(nb);
        str = NULL;
    }
}
