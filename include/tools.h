/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef MY_TOOLS
#define MY_TOOLS

sfVector2i *get_pts(int x1, int y1, int x2, int y2);
sfVector2i get_vector2i(int y, int x);
sfVector2f get_2pts(sfVector3f in);
sfVector2f rot(sfVector2f *p, int rot);
sfVector3f trans_iso(info_t *cam, int y, int x, int z);
sfVector2f get_vector2f(float y, float x);

#endif
