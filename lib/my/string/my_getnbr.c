/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** convert str en int
*/

int my_getnbr(char const *str)
{
    long int nb = 0;
    int negatif = 0;
    int frame = -1;
    int i = -1;

    while ((str[++i] < '0' || '9' < str[i]) && str[i] != '\0' && ++frame > -1);
    negatif = (frame > -1 && str[frame] == '-') ? 1 : 0;
    i = frame;
    while ('0' <= str[++i] && str[i] <= '9' && str[i] != '\0') {
        nb *= 10;
        nb += str[i] - '0';
    }
    nb *= (negatif == 1) ? -1 : 1;
    return ((int)nb);
}
