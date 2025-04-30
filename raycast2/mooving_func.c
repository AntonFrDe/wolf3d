/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** mooving_func
*/

#include "wolf.h"
#include <math.h>

static int is_loc_in_square(sfVector2f loc, sfVector2f square_loc, sfVector2f square_size)
{
    if (loc.x < square_loc.x ||
        loc.x > (square_loc.x + square_size.x))
        return 0;
    if (loc.y < square_loc.y ||
        loc.y > (square_loc.y + square_size.y))
        return 0;
    return 1;
}

int is_loc_in_map(sfVector2f loc, const map_t map)
{
    int boool = 0;

    for (int i = 0; i != map.size.x; i++) {
        for (int j = 0; j != map.size.y; j++)
            boool += (is_loc_in_square(loc, (sfVector2f ){.y = i * map.wall_size.y,
                .x = j * map.wall_size.x}, map.wall_size) == 1 && map.wall[i][j] == 1);
        if (boool > 0)
            return 1;
    }
    return 0;
}

sfVector2f angle_coor(sfVector2f point_coor, float angle, float len_circle)
{
    sfVector2f point;

    point.x = point_coor.x + len_circle * cos(pi / 180 * angle);
    point.y = point_coor.y + len_circle * sin(pi / 180 * angle);
    return point;
}
