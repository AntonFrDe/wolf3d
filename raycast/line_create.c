/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** line_create
*/

#include "include/my.h"
#include "include/struct.h"

void draw_line(sfRenderWindow *window, sfVector2f point2,
    sfVector2f point1, sfColor color)
{
    sfVertex vertex1 = {.position = point1, .color = color};
    sfVertex vertex2 = {.position = point2, .color = color};
    sfVertexArray *varr = sfVertexArray_create();

    sfVertexArray_append(varr, vertex1);
    sfVertexArray_append(varr, vertex2);
    sfVertexArray_setPrimitiveType(varr, sfLinesStrip);
    sfRenderWindow_drawVertexArray(window, varr, NULL);
    sfVertexArray_destroy(varr);
}

line_t create_line(sfVector2f point1, sfVector2f point2, sfColor color)
{
    line_t line;
    sfVertex vertex1 = {.position = point1, .color = color};
    sfVertex vertex2 = {.position = point2, .color = color};

    line.varr = sfVertexArray_create();
    line.p1 = point1;
    line.p2 = point2;
    line.color = color;
    sfVertexArray_append(line.varr, vertex1);
    sfVertexArray_append(line.varr, vertex2);
    sfVertexArray_setPrimitiveType(line.varr, sfLinesStrip);
    return line;
}
