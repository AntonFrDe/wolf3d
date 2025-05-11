/*
** EPITECH PROJECT, 2025
** weapon_hud
** File description:
** Initialization
*/

#include "../../include/context.h"
#include <SFML/Graphics.h>
#include "../../../raycasting3/include/struct.h"

void init_all(context_t *ctx, game_t *game)
{
    // sfVideoMode mode = {1920, 1080, 32};
    sfVector2f scale = {1.3f, 1.3f};
    sfVector2f offset = {60.f, 70.f};
    sfVector2u win_size;

    // ctx->window = sfRenderWindow_create(mode, "hud", sfResize | sfClose, NULL);
    ctx->window = game->window;
    win_size = sfRenderWindow_getSize(ctx->window);
    ctx->weapon = create_weapon("../overlay/src/assets/weapon.png", win_size, scale, offset);
    ctx->hud = create_hud("../overlay/src/assets/hud2.png");
    ctx->ammo = create_ammo_display();
    update_ammo_text(&ctx->ammo);
}
