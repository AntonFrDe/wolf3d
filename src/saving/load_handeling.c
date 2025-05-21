/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** load_handeling
*/

#include "../include/wolf.h"
#include <stdio.h>

static int load_loc(char **line_arr, player_t *player)
{
    sfVector2f loc;

    if (my_arrlen(line_arr) != 3)
        return 1;
    loc.x = atof(line_arr[1]);
    loc.y = atof(line_arr[2]);
    if (loc.x < 0 || loc.y < 0)
        return 1;
    player->loc = loc;
    free(line_arr);
    return 0;
}

static int load_mun(char **line_arr, int *ammo)
{
    int mun;

    if (my_arrlen(line_arr) != 2)
        return 1;
    mun = atoi(line_arr[2]);
    if (mun < 0)
        return 1;
    *ammo = mun;
    free(line_arr);
    return 0;
}

static int load_dir(char **line_arr, player_t *player)
{
    sfVector2f dir;

    if (my_arrlen(line_arr) != 3)
        return 1;
    dir.x = atof(line_arr[1]);
    dir.y = atof(line_arr[2]);
    if (dir.x < 0 || dir.y < 0)
        return 1;
    player->dir = dir;
    free(line_arr);
    return 0;
}

static int load_plan(char **line_arr, player_t *player)
{
    sfVector2f plane;

    if (my_arrlen(line_arr) != 3)
        return 1;
    plane.x = atof(line_arr[1]);
    plane.y = atof(line_arr[2]);
    if (plane.x < 0 || plane.y < 0)
        return 1;
    player->plane = plane;
    free(line_arr);
    return 0;
}

static int handle_load(char **line_arr, int *ammo, player_t *player)
{
    float nb1;
    float nb2;

    if (strcmp(line_arr, "loc") == 0)
        return load_loc(line_arr, player);
    if (strcmp(line_arr, "mun") == 0)
        return load_mun(line_arr, ammo);
    if (strcmp(line_arr, "dir") == 0)
        return load_dir(line_arr, player);
    if (strcmp(line_arr, "plan") == 0)
        return load_plan(line_arr, player);
    return 1;
}

game_t *load_file(char *filename, game_t *game)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t size = 0;
    int load_success = 0;
    int ammo;
    player_t player;

    if (file <= 0)
        return game;
    for (; getline(&line, &size, file) != -1; load_success++)
        if (handle_load(my_str_to_word_array(line, ";\n"), &ammo, &player))
            load_success = 0;
    if (load_success == 3) {
        game->player = player;
        game->context.ammo.ammo = ammo;
    }
    free(line);
    fclose(file);
    return game;
}
