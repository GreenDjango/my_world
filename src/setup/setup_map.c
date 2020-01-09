/*
** EPITECH PROJECT, 2019
** Project C : my_world
** File description:
** Is a terraformer program.
*/

#include <stdlib.h>
#include <dirent.h>
#include "main_struct.h"
#include "lib/my_string.h"
#include "config.h"

void check_name_map(char ***all_map, struct dirent *result, char pat[], int z)
{
    int tmp = all_map[z][0][0] + 1;
    int y = 0;

    for (int i = 0; result->d_name[i] != '\0'; i++)
        y += (result->d_name[i] == pat[y]) ? 1 : 0;
    if (result->d_name[0] != '.' && y == my_strlen(pat) && tmp < 30) {
        all_map[z][0][0] += 1;
        all_map[z][tmp] = malloc(my_strlen(result->d_name)+1);
        my_strcpy(all_map[z][tmp], result->d_name);
    }
}

char ***find_map(void)
{
    char ***all_map = malloc(sizeof(char **) * 2);
    DIR *fdd = opendir(FOLDER_MAP);
    struct dirent *result;

    all_map[0] = malloc(sizeof(char *) * 30);
    all_map[1] = malloc(sizeof(char *) * 30);
    all_map[0][0] = malloc(sizeof(char) * 1);
    all_map[1][0] = malloc(sizeof(char) * 1);
    all_map[0][0][0] = all_map[1][0][0] = 0;
    if (fdd != NULL) {
        result = readdir(fdd);
        for (int i = 1; result; i++) {
            check_name_map(all_map, result, ".legend", 0);
            check_name_map(all_map, result, ".3d", 1);
            result = readdir(fdd);
        }
        closedir(fdd);
    }
    return (all_map);
}
