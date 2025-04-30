/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** create_quad
*/

#include "wolf.h"

sfVertexArray *create_quad(sfVector2f *point, sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = point[0], .color = color};
    sfVertex vertex2 = {.position = point[1], .color = color};
    sfVertex vertex3 = {.position = point[2], .color = color};
    sfVertex vertex4 = {.position = point[3], .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    free(point);
    return (vertex_array);
}
