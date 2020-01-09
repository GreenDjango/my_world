/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#ifndef MY_CONFIG
#define MY_CONFIG

//Window
#define WINX (1920)
#define WINY (1080)

//MENU
#define NB_TEXTURE (8)
#define MENU_OPT (6)
#define FOLDER_MAP "data/map/"
#define MENU_STR "Start iso", "Start 3D", "Quit", "Back", "Start", "New"
#define GAME_INFO "P zoom in\nM zoom out\nARROW move map\n\nT print texture\n\
R rotate texture\n\nC contains 3 tools, which can be activated\nwith the left\
and the right click\nC up or down face point\nC up or down face\nC rest or up\
to max face\n"

// Engine (allocated ressources)
#define FOLDER_BLOCK "data/blc/"
#define MAX_MAP_SIZE (60) // dont increase more 60 (hight cpu)
#define NB_MAX_BLOCK ((MAX_MAP_SIZE + 2) * (MAX_MAP_SIZE + 2))
#define NB_TEX_BLOCK (47)

//start
#define START_ZOOM (100);
#define START_TRANSLATE_X ((WINX / 2) - 20)
#define START_TRANSLATE_Y ((WINY / 2) - 400)
#define SIDE_BLOCK (-40)

//optimization
#define ANGLE_X (cos(45 * M_PI/180)) //cos(45 * M_PI/180)
#define ANGLE_Y (sin(30 * M_PI/180)) //sin(30 * M_PI/180)

#endif
