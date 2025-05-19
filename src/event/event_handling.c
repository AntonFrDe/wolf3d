/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** event_handling
*/

#include "../../include/wolf.h"
#include "../../include/struct.h"
#include <math.h>

static void move_forward(game_t *game, float speed)
{
    int x = (int)(game->player.loc.x + game->player.dir.x * speed);
    int y = (int)(game->player.loc.y + game->player.dir.y * speed);

    if (game->map[y][(int)game->player.loc.x] == 0)
        game->player.loc.y += game->player.dir.y * speed;
    if (game->map[(int)game->player.loc.y][x] == 0)
        game->player.loc.x += game->player.dir.x * speed;
}

static void move_backward(game_t *game, float speed)
{
    int x = (int)(game->player.loc.x - game->player.dir.x * speed);
    int y = (int)(game->player.loc.y - game->player.dir.y * speed);

    if (game->map[y][(int)game->player.loc.x] == 0)
        game->player.loc.y -= game->player.dir.y * speed;
    if (game->map[(int)game->player.loc.y][x] == 0)
        game->player.loc.x -= game->player.dir.x * speed;
}

static void strafe(game_t *game, float speed, int dir)
{
    float plane_x = game->player.plane.x * dir;
    float plane_y = game->player.plane.y * dir;
    int x = (int)(game->player.loc.x + plane_x * speed);
    int y = (int)(game->player.loc.y + plane_y * speed);

    if (game->map[y][(int)game->player.loc.x] == 0)
        game->player.loc.y += plane_y * speed;
    if (game->map[(int)game->player.loc.y][x] == 0)
        game->player.loc.x += plane_x * speed;
}

static void mooving_func(game_t *game)
{
    float move_speed = 0.1f;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_forward(game, move_speed);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_backward(game, move_speed);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        strafe(game, move_speed, -1);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        strafe(game, move_speed, 1);
}

void event_handling(game_t *game)
{
    mooving_func(game);
}
