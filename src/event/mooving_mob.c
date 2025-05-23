/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** mooving_mob
*/

#include "../../include/wolf.h"

void mooving_mob(game_t *game)
{
    sfIntRect rect = {.height = 64, .left = 0, .top = 0, .width = 64};
    float time = sfTime_asSeconds(sfClock_getElapsedTime(game->mob.anim));
    
    if (time >= 0.6)
        sfClock_restart(game->mob.anim);
    rect.left = 64 * (int)(time * 10);
    //if (time - (int)time == time)
        sfSprite_setTextureRect(game->mob.sp, rect);
}