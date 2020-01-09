/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** swap value
*/

void my_swap(void *value, void *value_two)
{
    void *tmp = value;

    value = value_two;
    value_two = tmp;
}
