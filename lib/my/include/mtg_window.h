/*
** EPITECH PROJECT, 2018
** moteur 2D : window
** File description:
** header file
*/

#ifndef MTG_WIND
#define MTG_WIND

#include <SFML/Window/Window.h>//sfUint32
#include <SFML/Graphics/Types.h>//sfRenderWindow,

sfRenderWindow *mtg_create_window(unsigned int wdh, unsigned int hgt,
char *name, sfUint32 style);

#endif
