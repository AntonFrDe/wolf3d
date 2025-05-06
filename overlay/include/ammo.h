/*
** EPITECH PROJECT, 2025
** weapon_hud
** File description:
** Ammo display struct and functions
*/

#ifndef AMMO_H_
    #define AMMO_H_
    #include <SFML/Graphics.h>

typedef struct ammo_display_s {
    int ammo;
    sfFont *font;
    sfText *text;
} ammo_display_t;

ammo_display_t create_ammo_display(void);
void update_ammo_text(ammo_display_t *display);

#endif /* !AMMO_H_ */
