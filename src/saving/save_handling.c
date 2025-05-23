/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** save_handling
*/

#include "../../include/wolf.h"

void save_file(char *filename, game_t *game)
{
    FILE *file = fopen(filename, "w");

    fprintf(file, "loc;%.0f;%.0f\n", game->player.loc.x,
        game->player.loc.y);
    fprintf(file, "mun;%d\n", game->context.ammo.ammo);
    fprintf(file, "dir;%.0f;%.0f\n", game->player.dir.x,
        game->player.dir.y);
    fprintf(file, "plane;%.0f;%.0f\n", game->player.plane.x,
        game->player.plane.y);
    fclose(file);
}
