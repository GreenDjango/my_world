/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <fcntl.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "lib/my_string.h"
#include "lib/my_system.h"
#include "engine/world.h"
#include "unistd.h"
#include "config.h"

int **setup_tab(int y, int x)
{
    int **out = malloc(sizeof(int *) * (y + 1));
    int i = -1;

    while (++i < y) {
        out[i] = malloc(sizeof(int) * x);
        for (int a = 0; a < x; a++)
            out[i][a] = 0;
    }
    out[i] = NULL;
    return (out);
}

void assign_value(int **map, int **tx, void **f_tx, void **f_map)
{
    *f_tx = tx;
    *f_map = map;
}

void extra_value_map(sfVector2i *size, char **cut)
{
    size->y = (unsigned int)my_getnbr(cut[1]);
    size->x = (unsigned int)my_getnbr(cut[2]);
    my_free(4, cut[1], cut[2], cut[0], cut);
}

void get_map(void **f_map, void **f_tx, sfVector2i *size, int fd)
{
    char *r = NULL;
    char **cut = NULL;
    int **map = NULL;
    int **tx = NULL;
    int i = -2;

    while ((r = get_next_line(fd)) && ++i > -2 && i < size->y * size->x) {
        if (i == -1 && (cut = my_str_to_word_array(r, ","))
        && !my_strcmp(cut[0], "[map iso]") && cut[1] && cut[2]) {
            extra_value_map(size, cut);
            map = setup_tab(size->y, size->x);
            tx = setup_tab(size->y, size->x);
        } else if (map && tx && r && r[1] && r[2] && r[3] && r[4]
        && map[i / size->y]) {
            map[i / size->y][i % size->y] = my_getnbr(r + 4);
            tx[i / size->y][i % size->y] = (unsigned int)my_getnbr(r);
        } else
            size->y = 0;
    }
    assign_value(map, tx, f_tx, f_map);
}

map_iso_t *read_map_iso(char *pathfile, sfVector2i *map_size)
{
    map_iso_t *iso = malloc(sizeof(map_iso_t));
    char *full_name = va_strcat(2, FOLDER_MAP, pathfile);
    int fd = open(full_name, O_RDWR);
    void *map = NULL;
    void *tx = NULL;

    if (fd < 0)
        return (NULL);
    get_map(&map, &tx, map_size, fd);
    iso->map_iso = (int **)(map);
    iso->texture = (int **)(tx);
    close(fd);
    my_free(1, full_name);
    return (iso);
}
