/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include "input.h"//    prototype called function

// ADD key detection
// 1 - (key_init) add : key[0] = add_key(game_state, sfKey, &funct, int data);
// 2 - increase NB_KEY_DETECT (allowed ressourced)
// 3 -  add the prototype of the called function in input.h
my_key_t *key_init(void)
{
    my_key_t *key = malloc(sizeof(my_key_t) * (NB_KEY_DETECT + 1));

    key[0] = add_key(10, sfKeyC, &change_mode, 1);
    key[1] = add_key(20, sfKeyLeft, &mouve_cam, 2);
    key[2] = add_key(20, sfKeyRight, &mouve_cam, 1);
    key[3] = add_key(20, sfKeyUp, &mouve_cam, 4);
    key[4] = add_key(20, sfKeyDown, &mouve_cam, 3);
    key[5] = add_key(20, sfKeyP, &zoom_cam, 1);
    key[6] = add_key(20, sfKeyM, &zoom_cam, 2);
    key[7] = add_key(10, sfKeyR, &rotate, 1);
    key[8] = add_key(11, sfKeyLeft, &change_range, 1);
    key[9] = add_key(11, sfKeyRight, &change_range, 2);
    key[10] = add_key(11, sfKeyReturn , &change_range, 3);
    key[11] = add_key(11, sfKeyEscape, &change_range, 4);
    key[12] = add_key(10, sfKeyT, &change_mode, 2);
    return (key);
}

my_key_t add_key(int st, sfKeyCode key, int (*pfunc)(void *pg, int set), int s)
{
    my_key_t my_key = {st, key, pfunc, s};

    return (my_key);
}

int check_key(void *pg, my_key_t *key_t, sfKeyCode key, int state)
{
    int i = -1;

    while (++i < NB_KEY_DETECT)
        if (key_t[i].state == state && key_t[i].key == key)
            return (key_t[i].pfunc(pg, key_t[i].setting));
    return (0);
}
