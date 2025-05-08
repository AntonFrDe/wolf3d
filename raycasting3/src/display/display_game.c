/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** display_game
*/

#include "../../include/wolf.h"
#include "../../../overlay/include/overlay.h"
#include "../../../overlay/include/context.h"
#include "../../../overlay/include/hud.h"
#include "../../../overlay/include/ammo.h"

void display_game(game_t *game, context_t *ctx, sfSound *reload, sfSound *fire)
{
    // sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        cast_ray(game);
        draw_minimap(game);
        // sfRenderWindow_display(game->window);
        if (sfRenderWindow_pollEvent(game->window, game->event)) {
            handle_events(ctx, game->event, fire, reload);
            event_handling(game);
        }
        update_weapon(&ctx->weapon, &ctx->ammo,
        sfRenderWindow_getSize(ctx->window));
        display_all(ctx);
        sfSleep(sfMilliseconds(16));
    }
}
