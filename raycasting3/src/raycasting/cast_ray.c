/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** cast_ray
*/

#include "../../include/wolf.h"
#include <stdlib.h>
#include <math.h>

static sfVector2f init_sidedist(game_t *game, raycast_t raycast)
{
    sfVector2f side_dist;

    if (raycast.ray_dir.x < 0) {
        side_dist.x = (game->player.loc.x - (int)game->player.loc.x)
            * raycast.delta_dist.x;
    } else
        side_dist.x = (1 + (int)game->player.loc.x - game->player.loc.x)
            * raycast.delta_dist.x;
    if (raycast.ray_dir.y < 0) {
        side_dist.y = (game->player.loc.y - (int)game->player.loc.y)
            * raycast.delta_dist.y;
    } else
        side_dist.y = (1 + (int)game->player.loc.y - game->player.loc.y)
            * raycast.delta_dist.y;
    return side_dist;
}

static raycast_t init_value(game_t *game, int i)
{
    raycast_t raycast;

    raycast.cam.x = 2.0f * i / (float)(game->video.width) - 1.0f;
    raycast.ray_dir.x = game->player.dir.x +
        game->player.plane.x * raycast.cam.x;
    raycast.ray_dir.y = game->player.dir.y +
        game->player.plane.y * raycast.cam.x;
    raycast.delta_dist.x = raycast.ray_dir.x == 0
        ? 1e30 : fabs(1 / raycast.ray_dir.x);
    raycast.delta_dist.y = raycast.ray_dir.y == 0
        ? 1e30 : fabs(1 / raycast.ray_dir.y);
    raycast.steps = (sfVector2i){raycast.ray_dir.x < 0 ? -1 : 1,
    raycast.ray_dir.y < 0 ? -1 : 1};
    raycast.side_dist = init_sidedist(game, raycast);
    raycast.hit = 0;
    return raycast;
}

void cast_ray(game_t *game)
{
    raycast_t raycast;

    sfRenderTexture_clear(game->gmtx.walltx, sfBlack);
    sfRenderTexture_drawSprite(game->gmtx.walltx, game->gmtx.skybg, NULL);
    for (int i = 0; i != (int)game->video.width; i++) {
        raycast = init_value(game, i);
        raycast = calc_dda(game, raycast);
        draw_txtr(game, raycast, i);
    }
    sfRenderTexture_display(game->gmtx.walltx);
}
