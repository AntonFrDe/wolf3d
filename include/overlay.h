/*
** EPITECH PROJECT, 2024
** overlay
** File description:
** overlay.h
*/

#include "SFML/Graphics.h"
#include "SFML/System.h"
#include "SFML/Audio.h"
#include "SFML/Window.h"

#ifndef WEAPON_H_
    #define WEAPON_H_
typedef struct weapon_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f original_pos;
    sfVector2f offset;
    int is_shooting;
    float shoot_offset;
    int is_reloading;
    float reload_offset;
    int is_flash;
    sfTexture *shoot_texture;
    sfSprite *shoot_sprite;
    sfIntRect shoot_frames[3];
    int shoot_index;
    int shoot_timer;
    sfBool is_fire_shooting;
} weapon_t;

typedef struct hud_s {
    sfTexture *texture;
    sfSprite *sprite;
} hud_t;

typedef struct ammo_display_s {
    int ammo;
    sfFont *font;
    sfText *text;
} ammo_display_t;

ammo_display_t create_ammo_display(void);
void update_ammo_text(ammo_display_t *display);

typedef struct context_s {
    sfRenderWindow *window;
    weapon_t weapon;
    ammo_display_t ammo;
    hud_t hud;
    sfSound *fire;
    sfSound *reload;
    sfVector2f shoot_fire_pos;
    sfSprite *crosshair;
} context_t;

hud_t create_hud(const char *filepath);
void draw_hud(sfRenderWindow *window, hud_t *hud);
void destroy_hud(hud_t *hud);
weapon_t create_weapon(const char *filepath,
    sfVector2u window_size, sfVector2f scale, sfVector2f offset);
void update_weapon(weapon_t *weapon, ammo_display_t *ammo,
    sfVector2u window_size);
#endif /* !WEAPON_H_ */
