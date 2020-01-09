/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare two string and return the difference
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i = -1;

    while (s1[++i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]);
    return (s1[i] - s2[i]);
}
