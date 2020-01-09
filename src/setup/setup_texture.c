/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "main_struct.h"
#include "config.h"
#include "setup.h"

//Get all the textures
void init_tex(int i, sfTexture *tex[NB_TEXTURE], sfSprite *spr[NB_TEXTURE])
{
    char *adress[NB_TEXTURE] = {"data/menu/menu.png", "data/menu/star.jpg",
        "data/menu/button.png", "data/menu/map.jpg", "data/menu/sound_icon.png",
        "data/menu/range.png", "data/game/toolbar.png", "data/game/msg.png"};
    sfImage *img = sfImage_createFromFile(adress[i]);

    spr[i] = sfSprite_create();
    tex[i] = sfTexture_createFromImage(img, NULL);
    sfImage_destroy(img);
    sfSprite_setTexture(spr[i], tex[i], sfFalse);
}

void apply_my_texture(texture_t *all_tex, sfTexture **tex, sfSprite **spr)
{
    all_tex->tex_menu_name = tex[0];
    all_tex->tex_menu_star = tex[1];
    all_tex->tex_menu_button = tex[2];
    all_tex->tex_menu_map = tex[3];
    all_tex->tex_menu_sound = tex[4];
    all_tex->tex_menu_range = tex[5];
    all_tex->tex_toolbar = tex[6];
    all_tex->tex_msg = tex[7];
    all_tex->spr_menu_name = spr[0];
    all_tex->spr_menu_star = spr[1];
    all_tex->spr_menu_map = spr[3];
    all_tex->spr_menu_sound = spr[4];
    all_tex->spr_menu_range = spr[5];
    all_tex->spr_toolbar = spr[6];
    all_tex->spr_msg = spr[7];
}

//create all sprites for the game
texture_t *create_texture(void)
{
    texture_t *all_tex = malloc(sizeof(texture_t));
    sfTexture *tex[NB_TEXTURE];
    sfSprite *spr[NB_TEXTURE];

    all_tex->rec_menu_button = malloc(sizeof(sfRectangleShape *) * MENU_OPT);
    for (int i = 0; i < NB_TEXTURE; i++)
        init_tex(i, tex, spr);
    apply_my_texture(all_tex, tex, spr);
    sfTexture_setSmooth(all_tex->tex_menu_star, sfTrue);
    sfSprite_destroy(spr[2]);
    create_screen_saver(all_tex);
    create_rectangle(all_tex, tex);
    return (all_tex);
}

music_game_t *create_music(void)
{
    music_game_t *all_msc = malloc(sizeof(music_game_t));

    all_msc->msc1 = sfMusic_createFromFile("data/music/main_music.ogg");
    all_msc->snd1 = sfMusic_createFromFile("data/music/click.ogg");
    sfMusic_setVolume(all_msc->snd1, 60.0);
    sfMusic_setVolume(all_msc->msc1, 50.0);
    sfMusic_setLoop(all_msc->msc1, sfTrue);
    sfMusic_play(all_msc->msc1);
    return (all_msc);
}
