/*
** EPITECH PROJECT, 2024
** FinalProject
** File description:
** hud.c
*/

#include "../../include/wolf.h"

hud_t create_hud(const char *filepath)
{
    hud_t hud;

    hud.texture = sfTexture_createFromFile(filepath, NULL);
    hud.sprite = sfSprite_create();
    sfSprite_setTexture(hud.sprite, hud.texture, sfTrue);
    sfSprite_setPosition(hud.sprite, (sfVector2f){0, 0});
    sfSprite_setScale(hud.sprite, (sfVector2f){1.5f, 1.46f});
    return hud;
}

void draw_hud(sfRenderWindow *window, hud_t *hud)
{
    sfRenderWindow_drawSprite(window, hud->sprite, NULL);
}

void draw_muzzle_flash(sfRenderWindow *window, particle_t *p)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(p->clock)) < sfTime_asSeconds(p->duration)) {
        sfRenderWindow_drawSprite(window, p->sprite, NULL);
    }
}


void destroy_hud(hud_t *hud)
{
    sfSprite_destroy(hud->sprite);
    sfTexture_destroy(hud->texture);
}
