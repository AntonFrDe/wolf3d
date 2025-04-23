/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** create_circle
*/

#include "include/my.h"
#include "include/struct.h"

circle_t create_circle(float radius, sfVector2f location, sfColor color)
{
    circle_t circle;

    location.x -= radius;
    location.y -= radius;
    circle.circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle.circle, radius);
    sfCircleShape_setFillColor(circle.circle, color);
    sfCircleShape_setPosition(circle.circle, location);
    circle.color = color;
    circle.location = location;
    circle.radius = radius;
    return circle;
}
