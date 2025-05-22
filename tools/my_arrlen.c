/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** my_arrlen
*/

#include "../include/wolf.h"

int my_arrlen(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return 0;
    for (; arr[i] != NULL; i++);
    return i;
}
