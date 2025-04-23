/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** init_ray
*/

#include "include/my.h"
#include "include/struct.h"
#include "math.h"

float ray_display(map_t map, sfVector2f center, float angle)
{
    sfVector2f point2;
    float i;
    float len;

    for (i = 0; is_loc_in_map(angle_coor(center, angle, i), map)
        == 0; i += 0.1)
        point2 = angle_coor(center, angle, i);
    len = sqrt(point2.x * point2.x + center.y * center.y) *
        cos(angle * 0.0174533);

    return i;
}

line_t init_ray(int angle)
{
    line_t line = create_line((sfVector2f ){x: 0, y: 0},
        (sfVector2f ){x: 0, y: 0}, sfGreen);

    line.angle = angle;
    line.lenght = 0;
    return line;
}
