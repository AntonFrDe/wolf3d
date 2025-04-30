/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** event_handling
*/

#include "wolf.h"

static bool hit_box(sfVector2f new_loc, map_t map)
{
    sfVector2f right = {.x = new_loc.x + 10, .y = new_loc.y};
    sfVector2f down = {.x = new_loc.x , .y = new_loc.y + 10};

    return is_loc_in_map(new_loc, map) == 0 &&
        is_loc_in_map(right, map) == 0  && 
        is_loc_in_map(down, map) == 0;
}

static void moove_player(game_t *game)
{
    sfVector2f new_loc;

    game->player.angle += sfKeyboard_isScancodePressed(sfKeyE) - sfKeyboard_isKeyPressed(sfKeyA);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        new_loc = angle_coor(game->player.loc, game->player.angle, 10);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        new_loc = angle_coor(game->player.loc, game->player.angle - 180, 10);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        new_loc = angle_coor(game->player.loc, game->player.angle - 90, 5);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        new_loc = angle_coor(game->player.loc, game->player.angle + 90, 5);
    if (hit_box(new_loc, game->map) == true)
        game->player.loc = new_loc;
}

void event_handling(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfWindow_close((sfWindow *)game->window.win);
    moove_player(game);
    set_ray(game);
    if (game->window.event.type == sfEvtKeyReleased)
        if (game->window.event.key.code == sfKeyY)
            game->show_map = game->show_map == false;
}
