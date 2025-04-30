/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** print_vector
*/

#include "wolf.h"

void print_2iv(sfVector2i vec)
{
    printf("{%d, %d}\n", vec.x, vec.y);
}

void print_2fv(sfVector2f vec)
{
    printf("{%f, %f}\n", vec.x, vec.y);
}
