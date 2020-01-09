/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "lib/my_string.h"
#include "lib/my_system.h"
#include "engine/world.h"
#include "config.h"

void get_save(int fd, map_iso_t *map, int y, int x)
{
    char *line = NULL;
    char *tp = NULL;

    if (map->texture[y][x] < 100)
        write(fd, "0", 1);
    if (map->texture[y][x] < 10)
        write(fd, "0", 1);
    line = my_convert_int_to_str(map->texture[y][x]);
    write(fd, line, my_strlen(line));
    write(fd, ",", 1);
    tp = my_convert_int_to_str(map->map_iso[y][x]);
    write(fd, tp, my_strlen(tp));
    write(fd, "\n", 1);
    my_free(2, line, tp);
}

void save_map_iso(map_iso_t *map, sfVector2i *size, char *name)
{
    char *full_name = va_strcat(3, FOLDER_MAP, name, ".legend");
    int fd = open(full_name, O_CREAT | O_WRONLY, S_IRWXU);
    char *sx = my_convert_int_to_str(size->x);
    char *sy = my_convert_int_to_str(size->y);

    if (fd < 0)
        return;
    write(fd, "[map iso],", 10);
    write(fd, sy, my_strlen(sy));
    write(fd, ",", 1);
    write(fd, sx, my_strlen(sx));
    write(fd, "\n", 1);
    for (int i = 0; i < size->y; i++)
        for (int a = 0; a < size->x; a++)
            get_save(fd, map, i, a);
    my_free(3, full_name, sx, sy);
    close(fd);
}
