/*
** EPITECH PROJECT, 2025
** B-PSU-200-TLS-2-1-minishell2-anton.franc-delbourg
** File description:
** my_superstrcat
*/

#include "../include/wolf.h"
#include <stdarg.h>

static int cp_str(char *str1, char *str2)
{
    int i = 0;

    for (i = 0; str2[i] != '\0'; i++)
        str1[i] = str2[i];
    return i;
}

char *my_superstrcat(char *target, int nb_elem, ...)
{
    va_list list;
    int len_total = 0;
    int parcour = 0;

    va_start(list, nb_elem);
    for (int i = 0; i != nb_elem; i++)
        len_total += strlen(va_arg(list, char *));
    va_end(list);
    va_start(list, nb_elem);
    target = malloc(sizeof(char) * len_total);
    for (int i = 0; i != nb_elem; i++)
        parcour += cp_str(&target[parcour], va_arg(list, char *));
    target[parcour] = '\0';
    return target;
}
