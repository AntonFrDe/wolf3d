/*
** EPITECH PROJECT, 2024
** FinalProject
** File description:
** update.c
*/

#include "../../include/wolf.h"

static void reset_weapon_position(weapon_t *weapon, sfVector2u win_size)
{
    sfFloatRect bounds = sfSprite_getLocalBounds(weapon->sprite);
    sfVector2f scale = sfSprite_getScale(weapon->sprite);

    weapon->original_pos.x = (win_size.x - bounds.width * scale.x)
        / 2 + weapon->offset.x;
    weapon->original_pos.y = (win_size.y - bounds.height * scale.y)
        / 2 + weapon->offset.y;
    sfSprite_setPosition(weapon->sprite, weapon->original_pos);
}

static void update_shoot(weapon_t *weapon, sfVector2u win_size)
{
    if (weapon->shoot_offset < 20) {
        weapon->shoot_offset += 4;
        sfSprite_move(weapon->sprite, (sfVector2f){0, -4});
    } else if (weapon->shoot_offset < 60) {
        weapon->shoot_offset += 2;
        sfSprite_move(weapon->sprite, (sfVector2f){0, 1});
    } else {
        weapon->is_shooting = 0;
        weapon->shoot_offset = 0;
        reset_weapon_position(weapon, win_size);
    }
}

static void update_reload(weapon_t *weapon, ammo_display_t *ammo,
    sfVector2u win_size)
{
    if (weapon->reload_offset < 15) {
        weapon->reload_offset += 1;
        sfSprite_move(weapon->sprite, (sfVector2f){0, 2});
    } else if (weapon->reload_offset < 30) {
        weapon->reload_offset += 1;
        sfSprite_move(weapon->sprite, (sfVector2f){0, -2});
    } else {
        weapon->is_reloading = 0;
        weapon->reload_offset = 0;
        reset_weapon_position(weapon, win_size);
        ammo->ammo = 32;
        update_ammo_text(ammo);
    }
}

void update_weapon(weapon_t *weapon, ammo_display_t *ammo,
    sfVector2u win_size)
{
    if (weapon->is_shooting)
        update_shoot(weapon, win_size);
    if (weapon->is_reloading)
        update_reload(weapon, ammo, win_size);
}
