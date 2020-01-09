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
void main_engine_iso_mode(program_t *pg);
map_iso_t *read_map_iso(char *pathfile, sfVector2i *map_size);
void refresh_iso_cords(engine_t *world);
void draw_map_iso(sfRenderWindow *wd, engine_t *world, program_t *pg);
int check_polygone(sfVector3f *pts, sfVector2i mouse, int size);
int check_detection_trinagle(sfVector3f *pts, sfVector2i mouse);
void check_hover_iso(program_t *pg, block_t *map, sfVector2i *mo, int *alive);
void refresh_hover_face(sfVector3f *pts, sfVertexArray *vt, int mode, int tx);
void change_height_iso(int mode, int va, program_t *pg, sfVector2i *emp);
void save_map_iso(map_iso_t *map, sfVector2i *size, char *name);
void create_new_map(char *name, int dim);
void free_iso_mode(program_t *pg);
void free_program(program_t *pg);

#endif
