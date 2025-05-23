/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** display_hud
*/

#include "../../include/wolf.h"

void display_hud(game_t *game)
{
    char *kills = malloc(sizeof(char) * 30);
    update_weapon(&game->context.weapon, &game->context.ammo,
    sfRenderWindow_getSize(game->window));
    sfRenderWindow_drawSprite(game->window, game->context.weapon.sprite, NULL);
    draw_hud(game->window, &game->context.hud);
    sfRenderWindow_drawText(game->window, game->context.ammo.text, NULL);
    if (game->mob.kills) {
        if (game->mob.kills == 1)
            sprintf(kills, "KILL : 1");
        if (game->mob.kills < 50 && game->mob.kills != 1)
            sprintf(kills, "KILLS : %d", game->mob.kills);
        if (game->mob.kills > 50)
            sprintf(kills, "MAX KILL YOU WON !!");
        draw_text_at(game, kills, (sfVector2f){game->video.height / 15,
            game->video.width / 15});
        free(kills);
    }   
}
