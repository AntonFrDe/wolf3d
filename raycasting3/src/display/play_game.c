/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** play_game
*/

#include "../../include/wolf.h"

switch_window_state_t play_game(game_t *game)
{
    game->context = init_overlay(game);
    while (game->state == STATE_GAME) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->skybg, NULL);
        cast_ray(game);
        draw_minimap(game);
        while (sfRenderWindow_pollEvent(game->window, game->event)) {
            game->state = event_handling(game);
            handle_events(&game->context, *game->event, game->context.fire,
                game->context.reload);
        }
        display_hud(game);
        sfRenderWindow_display(game->window);
        sfSleep(sfMilliseconds(16));
    }
    return game->state;
}
