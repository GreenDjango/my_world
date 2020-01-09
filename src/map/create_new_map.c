/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <fcntl.h>
#include <unistd.h>
#include "config.h"
#include "lib/my_string.h"
#include "lib/my_system.h"

void create_new_map(char *name, int dim)
{
    char *full_name = va_strcat(3, FOLDER_MAP, name, ".legend");
    int fd = open(full_name, O_CREAT | O_WRONLY, S_IRWXU);
    int size = dim + 2;
    char *sx;

    if (dim > MAX_MAP_SIZE || dim <= 0 || fd < 0)
        return;
    sx = my_convert_int_to_str(size);
    write(fd, "[map iso],", 10);
    write(fd, sx, my_strlen(sx));
    write(fd, ",", 1);
    write(fd, sx, my_strlen(sx));
    write(fd, "\n", 1);
    for (int i = 0; i < size * size; i++)
        write(fd, "000,0\n", 6);
    my_free(2, full_name, sx);
}
