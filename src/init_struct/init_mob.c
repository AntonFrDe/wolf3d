/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** init_mob
*/

#include "../../include/wolf.h"

mob_t init_mob(void)
{
    mob_t mob;
    sfIntRect rect = {.height = 64, .left = 0, .top = 0, .width = 64};

    mob.distance = 0;
    mob.pos = (sfVector2f){2, 2};
    mob.tx = sfTexture_createFromFile("Assets/AlienIdle.png", NULL);
    mob.sp = sfSprite_create();
    sfSprite_setTexture(mob.sp, mob.tx, sfTrue);
    sfSprite_setOrigin(mob.sp, (sfVector2f){64, 64});
    sfSprite_setTextureRect(mob.sp, rect);
    mob.kills = 0;
    return mob;
}
