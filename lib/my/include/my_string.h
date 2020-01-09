/*
** EPITECH PROJECT, 2018
** my_string
** File description:
** C-LIB
*/

#ifndef MY_STRING
#define MY_STRING

#define READ_SIZE (1)
#define MAX_SIZE_LINE (500)

int my_strlen(char const *str);
int my_putchar(char c);
int my_putstr(char *str);
int my_putnbr(int nb);
int my_put_error(char *msg, int return_line);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int size);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int size);
char *my_revstr(char *str);
int strcmp(const char *s1, const char *s2);
int my_nbrlen(long int nb);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int size);
char *my_convert_int_to_str(long int nb);
int my_getnbr(char const *str);
char *my_strcat(char *str1, char *str2);
char *va_strcat(int nb, ...);
char **my_str_to_word_array(char *str, char *sep);
int my_findchar(char const *src, char c);
char *get_next_line(int fd);
int my_printf(char *s, ...);

#endif
