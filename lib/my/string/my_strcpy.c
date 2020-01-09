/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Copies the string source into the string destination,
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = -1;

    while (src[++i] != '\0')
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
