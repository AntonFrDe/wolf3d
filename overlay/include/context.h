/*
** EPITECH PROJECT, 2024
** FinalProject
** File description:
** context.h
*/

#ifndef CONTEXT_H_
    #define CONTEXT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "overlay.h"
    #include "ammo.h"
    #include "hud.h"
    #include "../../raycasting3/include/struct.h"

typedef struct context_s {
    sfRenderWindow *window;
    weapon_t weapon;
    ammo_display_t ammo;
    hud_t hud;
} context_t;

void destroy_all(context_t *ctx,
    sfSound *fire, sfSoundBuffer *fbuf, sfSound *reload, sfSoundBuffer *rbuf);
void handle_events(context_t *ctx, sfEvent *event,
    sfSound *fire, sfSound *reload);
void display_all(context_t *ctx);
void init_all(context_t *ctx, game_t *game);

#endif /* !CONTEXT_H_ */
