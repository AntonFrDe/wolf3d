/*
** EPITECH PROJECT, 2024
** FinalProject
** File description:
** hud.h
*/

#ifndef HUD_H_
	#define HUD_H_
	#include <SFML/Graphics.h>

typedef struct hud_s {
    sfTexture *texture;
    sfSprite *sprite;
} hud_t;

hud_t create_hud(const char *filepath);
void draw_hud(sfRenderWindow *window, hud_t *hud);
void destroy_hud(hud_t *hud);

#endif /* !HUD_H_ */
