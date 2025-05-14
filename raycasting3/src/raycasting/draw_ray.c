/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** draw_ray
*/

#include "../../include/wolf.h"
#include "SFML/Graphics.h"

static sfColor color_ray(int wall, int side)
{
    sfColor color;

    switch (wall) {
    case 1:
        color = sfBlue;
        break;
    case 2:
        color = sfRed;
        break;
    case 3:
        color = sfGreen;
        break;
    default:
        color = sfYellow;
    }
    if (side == 1)
        color = (sfColor){.a = color.a, .r = color.r / 2,
            .g = color.g / 2, .b = color.b / 2};
    return color;
}

static void draw_line(sfRenderWindow *window, sfVector2f start,
    sfVector2f end, sfColor color)
{
    sfVertex line[2];

    line[0].position = start;
    line[0].color = color;
    line[1].position = end;
    line[1].color = color;
    sfRenderWindow_drawPrimitives(window, line, 2, sfLines, NULL);
}

void draw_ray(game_t *game, raycast_t raycast, int i)
{
    float distance = raycast.side == 0
        ? raycast.side_dist.x - raycast.delta_dist.x
        : raycast.side_dist.y - raycast.delta_dist.y;
    int len_line = distance > 0
        ? game->video.height / distance / 2
        : game->video.height / 0.01f / 2;
    sfColor line_color = {.a = 100, .r = 0, .g = 0, .b = 0};
    sfVector2f start = {.x = i, .y = -len_line + game->video.height / 2};
    sfVector2f end = {.x = i, .y = len_line + game->video.height / 2};

    if (start.y < 0)
        start.y = 0;
    if (end.y >= game->video.height)
        end.y = game->video.height - 1;
    draw_line(game->window, start, end, line_color);
}
