/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** draw_3d
*/

#include "wolf.h"
#include <math.h>

static float find_adj(ray_t ray, float player_angle)
{
    float angle_radians = (ray.angle - 180) * pi / 180.0f;
    float dx = ray.end.x - ray.start.x;
    float dy = ray.end.y - ray.start.y;
    float len = sqrtf(dx * dx + dy * dy); //  * cos(angle_radians - player_angle) ; 
    
    if (len < 0)
        len *= -1;
    return len;
}

static sfVector2f find_start(float dist, int i, float len)
{
    sfVector2f start;

    start.x = (dist * i) / 1000;
    start.y = HEIGHT / 2 - 350 + len;
    return start;
}

static sfVector2f find_end(float dist, int i, float len)
{
    sfVector2f end;

    end.x = (dist * i) / 1000;
    end.y = HEIGHT - len - 350;
    return end;
}

static sfColor change_color(float len)
{
    sfColor new_color = sfBlue;

    new_color.b -= len;
    if (new_color.b < 40)
        new_color.b = 40;
    //printf("color %d\n", new_color.b);
    return new_color;
}

void draw_3d(game_t *game)
{
    float dist = WIDTH * 1000 / RAY;
    float len;

    for (int i = 0; i != RAY; i++) {
        len = find_adj(game->player.rays[i], game->player.angle);
        draw_line(game->window.win, find_start(dist, i, len),
        find_end(dist, i, len), change_color(len));
    }
}


