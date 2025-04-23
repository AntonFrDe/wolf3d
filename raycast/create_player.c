/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** create_player
*/

#include "include/my.h"
#include "include/struct.h"

player_t *create_player(sfVector2f loc, int nb_ray)
{
    player_t *player = malloc(sizeof(player_t));

    player->dot = create_circle(10, loc, sfBlue);
    player->angle = 270;
    player->loc = loc;
    player->nb_ray = nb_ray;
    return player;
}
