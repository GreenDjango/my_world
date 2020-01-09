/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** calculate lengh of string
*/

int my_strlen(char const *str)
{
    int i = -1;

    while (str[++i] != '\0');
    return (i);
}
