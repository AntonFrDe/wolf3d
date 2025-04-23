/*
** EPITECH PROJECT, 2025
** BootStrap
** File description:
** draw_floor_and_ceilling
*/

#include "include/my.h"

sfRenderWindow *window_create(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "MyWoke",
        sfClose | sfResize, NULL);

    return window;
}

const sfVertexArray *top_vertex_array(void)
{
    sfVertexArray *top = sfVertexArray_create();
    sfVertex v1 = {.position = {.x = 0, .y = 0}, .color = sfRed};
    sfVertex v2 = {.position = {.x = 1920, .y = 0}, .color = sfRed};
    sfVertex v3 = {.position = {.x = 1920, .y = 1080 / 2}, .color = sfRed};
    sfVertex v4 = {.position = {.x = 0, .y = 1080 / 2}, .color = sfRed};

    sfVertexArray_append(top, v1);
    sfVertexArray_append(top, v2);
    sfVertexArray_append(top, v3);
    sfVertexArray_append(top, v4);
    return top;
}

const sfVertexArray *bot_vertex_array(void)
{
    sfVertexArray *bot = sfVertexArray_create();
    sfVertex v1 = {.position = {.x = 0, .y = 1080 / 2}, .color = sfGreen};
    sfVertex v2 = {.position = {.x = 1920, .y = 1080 / 2}, .color = sfGreen};
    sfVertex v3 = {.position = {.x = 1920, .y = 1080}, .color = sfGreen};
    sfVertex v4 = {.position = {.x = 0, .y = 1080}, .color = sfGreen};

    sfVertexArray_append(bot, v1);
    sfVertexArray_append(bot, v2);
    sfVertexArray_append(bot, v3);
    sfVertexArray_append(bot, v4);
    return bot;
}

void draw_floor_and_ceilling(sfRenderWindow *window)
{
    sfRenderStates state;

    sfRenderWindow_drawVertexArray(window, top_vertex_array(), &state);
    sfRenderWindow_drawVertexArray(window, bot_vertex_array(), &state);
}
