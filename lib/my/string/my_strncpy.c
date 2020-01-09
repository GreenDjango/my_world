/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Copies the string source into the string destination,
*/

char *my_strncpy(char *dest, char const *src, int size)
{
    int i = -1;

    while (src[++i] != '\0' && i < size)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
