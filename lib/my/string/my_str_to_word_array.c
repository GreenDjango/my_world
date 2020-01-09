/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** C-PROJECT
*/

#include <stdlib.h>

int check_sep(char c, char *sep)
{
    int i = -1;

    while (sep[++i] != '\0')
        if (sep[i] == c)
            return (1);
    return (0);
}

int count_words(char *str, char *sep, char c)
{
    int nb;

    if (*str == '\0')
        return (0);
    nb = count_words(str + 1, sep, *str);
    if (check_sep(c, sep) == 1 && check_sep(*str, sep) == 0)
        nb += 1;
    return (nb);
}

int mouve_to_next_word_and_get_size(char *str, int *i, char *sep)
{
    int size = -1;

    while (str[*i] != '\0' && check_sep(str[*i], sep) == 1)
        (*i)++;
    while (str[++size + (*i)] != '\0' && check_sep(str[*i], sep) == 0);
    return (size);
}

char *get_next_word(char *str, int *i, char *sep)
{
    int size = mouve_to_next_word_and_get_size(str, i, sep);
    char *word = NULL;
    int a = -1;

    if (size == 0)
        return (NULL);
    word = malloc(sizeof(char) * (size + 1));
    while (str[(*i)] != '\0' && check_sep(str[*i], sep) == 0 && a < size)
        word[++a] = str[(*i)++];
    word[a + 1] = '\0';
    return (word);
}

char **my_str_to_word_array(char *str, char *sep)
{
    int nb_words = count_words(str, sep, sep[0]);
    char **out = malloc(sizeof(char *) * (nb_words + 1));
    int cursor = 0;
    int i = -1;

    if (!out)
        return (NULL);
    while (++i < nb_words)
        out[i] = get_next_word(str, &cursor, sep);
    out[i] = NULL;
    return (out);
}
