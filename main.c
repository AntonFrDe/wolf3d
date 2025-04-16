/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** main
*/

#include "include/wolf.h"
#include <stdio.h>

void draw_floor_and_ceiling(sfRenderWindow *window)
{
    sfTexture *floor_texture;
    sfSprite *floor_sprite;

    floor_texture = sfTexture_create(100, 100);
    floor_sprite = sfSprite_create();
    sfSprite_setTexture(floor_sprite, floor_texture, sfTrue);
    sfRenderWindow_drawSprite(window, floor_sprite, NULL);
}

int is_wall(int x, int y)
{
    if (map[x, y] == 1)
        return 1;
    return 0;
}

void init_player(Player *player)
{
    player->x = 100;
    player->y = 100;
    player->angle = 0;
}

int events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Window", sfResize | sfClose, NULL);
    Player *player;

    while (sfWindow_isOpen(window)) {
        events(window);
    }
    init_player(player);
    return 0;
}
