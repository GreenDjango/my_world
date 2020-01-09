/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** C-Project
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_string.h"
#include "../include/my_system.h"

char *cut_and_push(char *str, int emp_n, char *buffer)
{
    char *out = NULL;

    if (emp_n == -1 && *str != '\0')
        return (str);
    if (!str || *str == '\0' || emp_n == 0)
        return (NULL);
    my_strcpy(buffer, str + emp_n + 1);
    out = my_strndup(str, emp_n);
    return (out);
}

void push_to_end_and_reset(char *src, char *dest)
{
    int size_dest = my_strlen(dest);
    int i = -1;

    while (src[++i] != '\0' && size_dest + i < MAX_SIZE_LINE)
        dest[size_dest + i] = src[i];
    dest[size_dest + i] = '\0';
    i = -1;
    while (src[++i] != '\0')
        src[i] = '\0';
}

char *get_next_line(int fd)
{
    static char buffer[(READ_SIZE > 1000) ? 1001 : READ_SIZE] = {'\0'};
    char *line = malloc(sizeof(char *) * (MAX_SIZE_LINE + 1));
    int read_info = 0;
    int emp_n = -1;
    int i = -1;

    if (fd < 0 || READ_SIZE <= 0 || READ_SIZE > 1000 || !line)
        return (NULL);
    while (++i < MAX_SIZE_LINE)
        line[i] = '\0';
    do {
        if (*buffer != '\0')
            push_to_end_and_reset(buffer, line);
        read_info = read(fd, buffer, READ_SIZE);
        push_to_end_and_reset(buffer, line);
    } while ((emp_n = my_findchar(line, '\n')) == -1 && read_info > 0);
    return (cut_and_push(line, emp_n, buffer));
}
