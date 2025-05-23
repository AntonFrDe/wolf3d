/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** draw_obj
*/

#include "../../include/wolf.h"

int draw_obj(game_t *game)
{
    sfVector2f dir = {
        .x = game->mob.pos.x - game->player.loc.x,
        .y = game->mob.pos.y - game->player.loc.y
    };
    float inv_det = 1.0f / (game->player.plane.x * game->player.dir.y -
                            game->player.dir.x * game->player.plane.y);
    sfVector2f transform = {
        .x = inv_det * (game->player.dir.y * dir.x - game->player.dir.x * dir.y),
        .y = inv_det * (-game->player.plane.y * dir.x + game->player.plane.x * dir.y)
    };
    int screen_x = (int)((game->video.width / 2) * (1 + transform.x / transform.y));
    float scale = game->video.height / transform.y * 2;

    if (transform.y >= game->gmtx.raybuff[screen_x] || transform.y <= 0)
        return 0;
    sfSprite_setScale(game->mob.sp, (sfVector2f){scale / 64, scale / 64});
    sfSprite_setPosition(game->mob.sp, (sfVector2f){
        screen_x, game->video.height / 2 + scale / 2
    });
    game->mob.distance = dir.x * dir.x + dir.y * dir.y;
    return 1;
}
