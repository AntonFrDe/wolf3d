/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** display_hud
*/

#include "../../include/wolf.h"

static void display_kills(game_t *game)
{
    char *kills = malloc(sizeof(char) * 30);
    int size = 50;

    if (game->mob.kills == 1)
        sprintf(kills, "KILL : 1");
    if (game->mob.kills < 20 && game->mob.kills != 1)
        sprintf(kills, "KILLS : %d", game->mob.kills);
    if (game->mob.kills >= 20) {
        sprintf(kills, "WIN");
        size *= 10;
    }
    draw_text_at(game, kills, (sfVector2f){game->video.height / 15,
        game->video.width / 15}, size);
    free(kills);
}

void display_hud(game_t *game)
{
    update_weapon(&game->context.weapon, &game->context.ammo,
    sfRenderWindow_getSize(game->window));
    sfRenderWindow_drawSprite(game->window, game->context.weapon.sprite, NULL);
    draw_hud(game->window, &game->context.hud);
    sfRenderWindow_drawText(game->window, game->context.ammo.text, NULL);
    if (game->mob.kills)
        display_kills(game);
}
