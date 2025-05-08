/*
** EPITECH PROJECT, 2024
** FinalProject
** File description:
** context.h
*/

#ifndef CONTEXT_H_
    #define CONTEXT_H_
    #include <SFML/Graphics.h>
    #include "overlay.h"
    #include "ammo.h"
    #include "hud.h"

typedef struct context_s {
    sfRenderWindow *window;
    weapon_t weapon;
    ammo_display_t ammo;
    hud_t hud;
} context_t;

#endif /* !CONTEXT_H_ */
