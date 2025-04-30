/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** render_display
*/

#include "wolf.h"

static void draw_minimap(game_t *game)
{
    for (int i = 0; i != game->map.size.x; i++)
        for (int j = 0; j != game->map.size.y; j++)
            sfRenderWindow_drawVertexArray(game->window.win,
                game->map.vertex[i][j], NULL);
    sfCircleShape_setPosition(game->player.circle, game->player.loc);
    sfRenderWindow_drawCircleShape(game->window.win, game->player.circle, NULL);
    draw_ray(game);
}

void render_display(game_t *game)
{
    sfRenderWindow_drawVertexArray(game->window.win, game->map.ground, NULL);
    draw_3d(game);
    if (sfKeyboard_isKeyPressed(sfKeyM))
        draw_minimap(game);
}
