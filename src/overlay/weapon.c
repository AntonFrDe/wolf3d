/*
** EPITECH PROJECT, 2024
** FinalProject
** File description:
** weapon.c
*/

#include "../../include/wolf.h"

weapon_t create_weapon(const char *filepath,
    sfVector2u window_size, sfVector2f scale, sfVector2f offset)
{
    weapon_t weapon;
    sfFloatRect bounds;

    weapon.texture = sfTexture_createFromFile(filepath, NULL);
    weapon.sprite = sfSprite_create();
    sfSprite_setTexture(weapon.sprite, weapon.texture, sfTrue);
    sfSprite_setScale(weapon.sprite, scale);
    weapon.offset = offset;
    bounds = sfSprite_getLocalBounds(weapon.sprite);
    weapon.original_pos.x = (window_size.x - bounds.width * scale.x)
        / 2 + offset.x;
    weapon.original_pos.y = (window_size.y - bounds.height * scale.y)
        / 2 + offset.y;
    sfSprite_setPosition(weapon.sprite, weapon.original_pos);
    weapon.is_shooting = 0;
    weapon.shoot_offset = 0;
    weapon.is_reloading = 0;
    weapon.reload_offset = 0;
    weapon.is_flash = 0;
    return weapon;
}
