/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef MY_INPUT
#define MY_INPUT

#include <SFML/System/Vector2.h>//  sfVector2f
#include <SFML/Window/Keyboard.h>//  sfKey
#include "config.h"

#define NB_KEY_DETECT (13)
#define NB_ZONE_CLICK (MENU_OPT + NB_TEX_BLOCK + 10)
#define NB_ZONE_HOVER (1)

//Prototype function called (MOUSE)
int button_event(void *pg, int setting);
int slide_map_preview(void *pg, int setting);
int pause_music(void *pg, int setting);
int change_range(void *pg, int setting);
int slide_tool(void *pg, int setting);
int texture_event(void *pg, int setting);
int exit_game(void *gp, int setting);

//Prototype function called (KEY)
int change_mode(void *pg, int mode);
int mouve_cam(void *pg, int direction);
int zoom_cam(void *pg, int direction);
int rotate(void *pg, int direction);

//Prototype function called (HOVER)
int show_help(void *gp, int setting);

/*  Input detection :
        -state (state of game)
        -emp (zone detection) || key
        -pfunction (call when mouse is in emp)
        -setting = data input */
typedef struct my_click_s
{
    int state;
    int button_used;
    sfVector2i *emp;
    int (*pfunc)(void *pg, int setting);
    int setting;
} my_click_t;

typedef struct my_key_s
{
    int state;
    sfKeyCode key;
    int (*pfunc)(void *pg, int setting);
    int setting;
} my_key_t;

typedef struct input_s
{
    my_click_t *clk;
    my_click_t *hover_clk;
    my_key_t *key;
} input_t;

typedef struct inp_info_s
{
    int state;
    int menu;
    int mod;
    int button;
} inp_info_t;

//Prototype setup
my_key_t *key_init(void);
my_key_t add_key(int st, sfKeyCode key, int (*pfunc)(void *pg, int set), int s);
my_click_t *hover_init(void);
my_click_t *click_init(void *pgg);
sfVector2i *get_pts(int x1, int y1, int x2, int y2);
my_click_t add_zone(int st, sfVector2i *pt, int (*pf)(void *pg, int s), int bu);

//Prototype check
int check_key(void *pg, my_key_t *key_t, sfKeyCode key, int state);
int check_zone(void *pg, my_click_t *clk, inp_info_t *info, sfVector2i *mouse);
int check_hover(void *pg, my_click_t *clk, inp_info_t *info, sfVector2i *mouse);

#endif
