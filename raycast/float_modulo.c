/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** float_modulo
*/

#include "include/my.h"

float float_modulo(float nb, float op)
{
    for (; nb >= op; nb -= op);
    return nb;
}
