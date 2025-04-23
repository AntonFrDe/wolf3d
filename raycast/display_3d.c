/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** display_3d
*/

#include "include/my.h"
#include "include/struct.h"

static sfVector2f *make_point(sfVector2f loc, int lenght, int height)
{
    sfVector2f *arr = malloc(sizeof(sfVector2f) * 4);

    arr[0] = loc;
    arr[1] = (sfVector2f){.x = loc.x + lenght, .y = loc.y};
    arr[3] = (sfVector2f){.x = loc.x, .y = loc.y + height};
    arr[2] = (sfVector2f){.x = loc.x + lenght, .y = loc.y + height};
    return arr;
}

a3d_t *init_3d(sfVector2f loc, int nb_lines, int lenght, int height)
{
    a3d_t *three_d = malloc(sizeof(a3d_t));

    three_d->lenght = lenght;
    three_d->height = height;
    three_d->loc = loc;
    three_d->br_color = sfBlack;
    three_d->border = create_quad(make_point(loc, lenght, height), sfBlack);
    three_d->nb_lines = nb_lines;
    three_d->lines = malloc(sizeof(line_t) * nb_lines);
    return three_d;
}

static sfVector2f find_end_start(float lenght, float y, float height)
{
    sfVector2f start_end;

    lenght *= 3;
    start_end.x = y + lenght;
    start_end.y = y + height - lenght;
    return start_end;
}

void display_3d(map_t map, player_t *player, sfRenderWindow *window,
    a3d_t *a3d)
{
    float line_dis = a3d->lenght / a3d->nb_lines;
    float len;
    float sep_ray = 90 / RAY;
    sfVector2f start_end;
    sfVector2f start;
    sfVector2f end;

    sfRenderWindow_drawVertexArray(window, a3d->border, NULL);
    for (float i = 0; i != a3d->nb_lines; i++) {
        len = ray_display(map, player->loc, player->angle - 45 / 2 + i * 0.1);
        start_end = find_end_start(len, a3d->loc.y, a3d->height);
        start = (sfVector2f){a3d->loc.x + 50 + i * line_dis, start_end.x};
        end = (sfVector2f){a3d->loc.x + 50 + i * line_dis, start_end.y};
        draw_line(window, start, end, sfBlue);
    }
}
