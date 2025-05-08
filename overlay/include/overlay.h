/*
** EPITECH PROJECT, 2024
** overlay
** File description:
** overlay.h
*/

/*
** EPITECH PROJECT, 2025
** weapon_hud
** File description:
** Weapon struct and functions
*/

#ifndef WEAPON_H_
	#define WEAPON_H_
	#include <SFML/Graphics.h>
	#include "ammo.h"
    #include <SFML/Audio.h>

typedef struct weapon_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f original_pos;
    sfVector2f offset;
    int is_shooting;
    float shoot_offset;
    int is_reloading;
    float reload_offset;
} weapon_t;

weapon_t create_weapon(const char *filepath,
    sfVector2u window_size, sfVector2f scale, sfVector2f offset);
void update_weapon(weapon_t *weapon, ammo_display_t *ammo,
    sfVector2u window_size);

#endif /* !WEAPON_H_ */
