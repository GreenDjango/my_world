/*
** EPITECH PROJECT, 2018
** my_findchar
** File description:
** return emp of this char in the string (-1 if not found)
*/

int my_findchar(char const *src, char c)
{
    int i = -1;

    while (src[++i] != '\0')
        if (src[i] == c)
            return (i);
    return (-1);
}
