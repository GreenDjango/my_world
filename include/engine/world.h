/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef MY_ENGINE
#define MY_ENGINE

#include <SFML/System.h>
#include <SFML/Graphics.h>

typedef struct face_s
{
    sfVertexArray *polygone;
    sfVertexArray *line;
    int *point;
    float depth_z;
    int texture;
} face_t;

typedef struct block_s
{
    sfVector2i map_emp;
    sfVector3f *pts;
    face_t *face;
} block_t;

typedef struct info_s
{
    int key;
    int souris_button;
    sfVector2i emp;
    sfVector2i translate;
    int zoom;
    sfVector2i map_size;
    int mode_modif;
    int pos_hover;
    int is_translate;
    int is_zoom;
    int is_x_value;
    int rot;
} info_t;

typedef struct map_iso_s
{
    int **map_iso;
    int **texture;
} map_iso_t;

typedef struct engine_s
{
    int mode;
    int refresh;
    int *alive_blc;
    map_iso_t *iso;
    sfVector3f **map_3d;
    block_t *rendu;
    info_t *info;
    sfCircleShape *cursor;
    sfTexture **tx_blc;
    sfVertexArray *hover;
} engine_t;

#endif
