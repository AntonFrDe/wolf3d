/*
** EPITECH PROJECT, 2025
** B-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** angle_coor
*/

#include "include/my.h"
#include "include/struct.h"
#include "math.h"

sfVector2f angle_coor(sfVector2f point_coor, float angle, float len_circle)
{
    sfVector2f point;

    point.x = point_coor.x + len_circle * cos(pi / 180 * angle);
    point.y = point_coor.y + len_circle * sin(pi / 180 * angle);
    return point;
}
