/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** draw_ray
*/

#include "wolf.h"

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

void draw_ray(game_t *game)
{
    for (int i = 0; i != RAY; i++) {
        draw_line(game->window.win, game->player.rays[i].start,
            game->player.rays[i].end, sfGreen);
    }
}

void set_ray(game_t *game)
{
    float ecart = 6000 / RAY;

    for (int i = 0; i != RAY; i++) {
        game->player.rays[i].start = (sfVector2f ){.x = game->player.loc.x + 2.5,
            .y = game->player.loc.y + 2.5};
        game->player.rays[i].end = game->player.loc;
        game->player.rays[i].angle = game->player.angle + (ecart * i) / 100 - 45;
        for (float len = 0; sfRenderWindow_isOpen(game->window.win) &&
         is_loc_in_map(game->player.rays[i].end, game->map) == 0; len++) {
            game->player.rays[i].end = angle_coor(
                game->player.rays[i].start, game->player.rays[i].angle, len);
        }
    }
}