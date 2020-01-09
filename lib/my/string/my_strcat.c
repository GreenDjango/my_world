/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** C-PROJECT
*/

#include <stdlib.h>
#include "../include/my_string.h"

char *my_strcat(char *str1, char *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    char *result = malloc(sizeof(char) * (size1 + size2 + 1));

    if (result == NULL)
        return (result);
    my_strcpy(result, str1);
    my_strcpy(result + size1, str2);
    result[size1 + size2] = '\0';
    return (result);
}
