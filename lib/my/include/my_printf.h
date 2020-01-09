/*
** EPITECH PROJECT, 2018
** my_printf.h
** File description:
** C-LIB
*/

typedef struct flag_s
{
    int (*pfunc)(va_list *list);
    char key;
} flag_t;

int flag_d(va_list *list);
int flag_c(va_list *list);
int flag_s(va_list *list);
