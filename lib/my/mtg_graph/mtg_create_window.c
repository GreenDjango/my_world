/*
** EPITECH PROJECT, 2018
** moteur 2D : create_window
** File description:
** generate and return sfRenderWindow
*/

#include <SFML/Window/Window.h>//           sfVideoMode, sfUint32
#include <SFML/Graphics/Types.h>//          sfRenderWindow,
#include <SFML/Graphics/RenderWindow.h>//   sfRenderWindow_create

sfRenderWindow *mtg_create_window(unsigned int wdh, unsigned int hgt,
char *name, sfUint32 style)
{
    sfVideoMode mode = {wdh, hgt, 8};
    sfRenderWindow *window;
    sfContextSettings setting = {0, 0, 5, 3, 0, 0, 0};

    window = sfRenderWindow_create(mode, name, style, &setting);
    return (window);
}
