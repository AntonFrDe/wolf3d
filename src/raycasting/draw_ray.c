/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** draw_ray
*/

#include "../../include/wolf.h"
#include "SFML/Graphics.h"

static sfColor color_ray(game_t *game, int i)
{
    sfColor color = sfBlack;

    color.a = 100;
    if (game->context.weapon.is_flash == 1 &&
        i > (int)game->video.width / 6 &&
        i < (int)game->video.width / 6 * 5) {
        color.a = 25;
        color.r = 255;
        color.g = 255;
        color.b = 255;
        return color;
    }
    return color;
}

static void draw_line(sfRenderTexture *texture, sfVector2f start,
    sfVector2f end, sfColor color)
{
    sfVertex line[2];

    line[0].position = start;
    line[0].color = color;
    line[1].position = end;
    line[1].color = color;
    sfRenderTexture_drawPrimitives(texture, line, 2, sfLines, NULL);
}

static void flashlight_ray(game_t *game, sfVector2f end, sfColor color, int i)
{
    sfVector2f vec = {.x = game->video.width / 2, .y = game->video.height};

    if (game->context.weapon.is_flash == 1
        && i > (int)game->video.width / 6 &&
        i < (int)game->video.width / 6 * 5)
        draw_line(game->gmtx.walltx, vec, end, color);
}

void draw_ray(game_t *game, raycast_t raycast, int i)
{
    float distance = raycast.side == 0
        ? raycast.side_dist.x - raycast.delta_dist.x
        : raycast.side_dist.y - raycast.delta_dist.y;
    int len_line = distance > 0
        ? game->video.height / distance / 2
        : game->video.height / 0.01f / 2;
    sfColor line_color = color_ray(game, i);
    sfVector2f start = {.x = i, .y = -len_line + game->video.height / 2};
    sfVector2f end = {.x = i, .y = len_line + game->video.height / 2};

    if (start.y < 0)
        start.y = 0;
    if (end.y >= game->video.height)
        end.y = game->video.height - 1;
    flashlight_ray(game, end, line_color, i);
    draw_line(game->gmtx.walltx, start, end, line_color);
}
