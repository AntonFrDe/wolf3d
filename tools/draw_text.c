/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** draw_text
*/

#include "../include/wolf.h"

void draw_text_at(game_t *game, const char *str, sfVector2f position, int size)
{
    sfText *text = sfText_create();

    if (!text || !game->app.font)
        return;
    sfText_setString(text, str);
    sfText_setFont(text, game->app.font);
    sfText_setCharacterSize(text, size);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}
