/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** draw_obj
*/

#include "../../include/wolf.h"


static int ray_x_mob(int screen_x, game_t *game)
{
    if (screen_x < (int)game->video.width / 6 ||
        screen_x > (int)game->video.width / 6 * 5) {
        return 1;
    }
    sfSprite_setColor(game->mob.sp, sfGreen);
    return 0;
}

static sfVector2f init_dir_vector(game_t *game)
{
    sfVector2f dir = { .x = game->mob.pos.x - game->player.loc.x,
        .y = game->mob.pos.y - game->player.loc.y};

    return dir;
}

static sfVector2f init_transform_vector(game_t *game, sfVector2f dir)
{
    float inv_det = 1.0f / (game->player.plane.x * game->player.dir.y -
        game->player.dir.x * game->player.plane.y);
    sfVector2f transform = {.x = inv_det * (game->player.dir.y * dir.x
        - game->player.dir.x * dir.y), .y = inv_det *
    (-game->player.plane.y * dir.x + game->player.plane.x * dir.y)};

    return transform;
}

int draw_obj(game_t *game)
{
    sfVector2f dir = init_dir_vector(game);
    sfVector2f transform = init_transform_vector(game, dir);
    int screen_x = (int)((game->video.width / 2) *
        (1 + transform.x / transform.y));
    float scale = game->video.height / transform.y * 2;

    sfSprite_setPosition(game->mob.sp, (sfVector2f){0, 0});
    sfSprite_setColor(game->mob.sp, sfWhite);
    if (transform.y <= 0 || !game->context.weapon.is_flash && (screen_x < 0 ||
        screen_x > (int)game->video.width - 1 ||
        transform.y >= game->gmtx.raybuff[screen_x]))
        return 0;
    if (game->context.weapon.is_flash)
        if (ray_x_mob(screen_x, game))
            return 0;
    sfSprite_setScale(game->mob.sp, (sfVector2f){scale / 64, scale / 64});
    sfSprite_setPosition(game->mob.sp, (sfVector2f){
        screen_x, game->video.height / 2 + scale / 2});
    game->mob.distance = dir.x * dir.x + dir.y * dir.y;
    return 1;
}
