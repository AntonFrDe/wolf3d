/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** event_handling
*/

#include "../../include/wolf.h"
#include "../../include/struct.h"
#include <math.h>
#define AIR 0
#define DOOR 2

static void move_forward(game_t *game, float speed)
{
    int x = (int)(game->player.loc.x + game->player.dir.x * speed);
    int y = (int)(game->player.loc.y + game->player.dir.y * speed);

    if (game->map[y][(int)game->player.loc.x] == AIR ||
        game->map[y][(int)game->player.loc.x] == DOOR)
        game->player.loc.y += game->player.dir.y * speed;
    if (game->map[(int)game->player.loc.y][x] == AIR ||
        game->map[(int)game->player.loc.y][x] == DOOR)
        game->player.loc.x += game->player.dir.x * speed;
}

static void move_backward(game_t *game, float speed)
{
    int x = (int)(game->player.loc.x - game->player.dir.x * speed);
    int y = (int)(game->player.loc.y - game->player.dir.y * speed);

    if (game->map[y][(int)game->player.loc.x] == AIR ||
        game->map[y][(int)game->player.loc.x] == DOOR)
        game->player.loc.y -= game->player.dir.y * speed;
    if (game->map[(int)game->player.loc.y][x] == AIR ||
        game->map[(int)game->player.loc.y][x] == DOOR)
        game->player.loc.x -= game->player.dir.x * speed;
}

static void strafe(game_t *game, float speed, int dir)
{
    float plane_x = game->player.plane.x * dir;
    float plane_y = game->player.plane.y * dir;
    int x = (int)(game->player.loc.x + plane_x * speed);
    int y = (int)(game->player.loc.y + plane_y * speed);

    if (game->map[y][(int)game->player.loc.x] == AIR ||
        game->map[(int)game->player.loc.y][x] == DOOR)
        game->player.loc.y += plane_y * speed;
    if (game->map[(int)game->player.loc.y][x] == AIR ||
        game->map[(int)game->player.loc.y][x] == DOOR)
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

static void rotate_player(game_t *game, float dist)
{
    float angle = dist > game->video.width / 2 ? -0.2f : 0.2f;
    float cos_a = cos(angle);
    float sin_a = sin(angle);
    float old_dir_x = game->player.dir.x;
    float old_plane_x = game->player.plane.x;

    game->player.dir.x = old_dir_x * cos_a - game->player.dir.y * sin_a;
    game->player.dir.y = old_dir_x * sin_a + game->player.dir.y * cos_a;
    game->player.plane.x = old_plane_x * cos_a - game->player.plane.y * sin_a;
    game->player.plane.y = old_plane_x * sin_a + game->player.plane.y * cos_a;
    game->player.angle -= angle * 100;
    game->player.angle %= 360;
}

static void turn_event(game_t *game)
{
    sfVector2i mouse_loc = sfMouse_getPositionRenderWindow(game->window);
    sfIntRect rect = {0, 0, 0, 0};
    float dist = mouse_loc.x;

    if (mouse_loc.x == game->video.width / 2 &&
        mouse_loc.y == game->video.height / 2)
        return;
    rotate_player(game, dist);
    rect.height = game->video.height / 2;
    rect.width = game->video.width;
    rect.left = game->player.angle;
    sfSprite_setTextureRect(game->gmtx.skybg, rect);
}

void event_handling(game_t *game)
{
    mooving_func(game);
    turn_event(game);
}
