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

static void rotate_player(game_t *game, float angle)
{
    float cos_a = cos(angle);
    float sin_a = sin(angle);
    float old_dir_x = game->player.dir.x;
    float old_plane_x = game->player.plane.x;

    game->player.dir.x = old_dir_x * cos_a - game->player.dir.y * sin_a;
    game->player.dir.y = old_dir_x * sin_a + game->player.dir.y * cos_a;
    game->player.plane.x = old_plane_x * cos_a - game->player.plane.y * sin_a;
    game->player.plane.y = old_plane_x * sin_a + game->player.plane.y * cos_a;
}

static void mooving_func(game_t *game, int mouse_dir)
{
    float move_speed = 0.1f;
    const float rot_speed = 0.01f;

    if (mouse_dir != 0)
        move_speed /= 10;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_forward(game, move_speed);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_backward(game, move_speed);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        strafe(game, move_speed, -1);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        strafe(game, move_speed, 1);
    if (mouse_dir != 0)
        rotate_player(game, rot_speed * mouse_dir);
}

switch_window_state_t event_handling(game_t *game)
{
    sfVector2i mouse_loc = sfMouse_getPositionRenderWindow(game->window);
    int mouse_dir = 0;
    sfVector2i center = {.x = game->video.width / 2, .y = game->video.height / 2};

    if (game->event->type == sfEvtKeyReleased &&
        game->event->key.code == sfKeyEscape)
        return STATE_MENU;
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    if (mouse_loc.x > center.x)
        mouse_dir = -1;
    if (mouse_loc.x < center.x)
        mouse_dir = 1;
    mooving_func(game, mouse_dir);
    return STATE_GAME;
}
