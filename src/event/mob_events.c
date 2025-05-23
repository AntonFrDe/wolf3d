/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** mooving_mob
*/

#include "../../include/wolf.h"

static sfVector2f new_mob_pos(game_t *game)
{
    int rand_x = rand() % ((int)game->map_size.x);
    int rand_y = rand() % ((int)game->map_size.y);

    while (game->map[rand_y][rand_x] != 0) {
        rand_x = rand() % ((int)game->map_size.x);
        rand_y = rand() % ((int)game->map_size.y);
    }
    return (sfVector2f){.x = rand_x, .y = rand_y};
}

void shooting_mob(game_t *game)
{
    int x = (int)sfSprite_getPosition(game->mob.sp).x;
    int scale = (int)sfSprite_getScale(game->mob.sp).x;
    int center = (int)game->video.width / 2;

    if (x > center - 128 * scale && x < center + 128 * scale ) {
        game->mob.pos = new_mob_pos(game);
        game->mob.kills++;
    }
}

void mooving_mob(game_t *game)
{
    sfIntRect rect = {.height = 64, .left = 0, .top = 0, .width = 64};
    float time = sfTime_asSeconds(sfClock_getElapsedTime(game->mob.anim));
    int key_frame = (int)(time * 10) % 4;

    if (time >= 0.6)
        sfClock_restart(game->mob.anim);
    rect.left = 64 * (int)(time * 10);
    if (key_frame == 0)
        sfSprite_setTexture(game->key.sp, game->key.tx1, sfTrue);
    if (key_frame == 1)
        sfSprite_setTexture(game->key.sp, game->key.tx2, sfTrue);
    if (key_frame == 2)
        sfSprite_setTexture(game->key.sp, game->key.tx3, sfTrue);
    if (key_frame == 3)
        sfSprite_setTexture(game->key.sp, game->key.tx4, sfTrue);
    sfSprite_setTextureRect(game->mob.sp, rect);
}
