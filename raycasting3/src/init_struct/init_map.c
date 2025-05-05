/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** init_map
*/

#include "wolf.h"
#include <stdio.h>

static int check_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] < '0' || line[i] > '9')
            return 84;
    return 0;
}

static sfVector2f map_size(char *map_file, sfVector2f map_size)
{
    FILE *file = fopen(map_file, "r");
    char *line = NULL;
    size_t size;
    int i = 0;

    if (file == NULL)
        return (sfVector2f){0, 0};
    for (; getline(&line, &size, file) != -1; i++) {
        line = remove_bsn(line);
        if (check_line(line) == 84)
            return (sfVector2f){0, 0};
        if (i == 0)
            map_size.x = strlen(line);
        if (strlen(line) != map_size.x)
            return (sfVector2f){0, 0};
    }
    free(line);
    fclose(file);
    map_size.y = i;
    return map_size;
}

static int **init_map_array(char *map_file, sfVector2f map_size)
{
    FILE *file = fopen(map_file, "r");
    char *line = NULL;
    size_t size;
    int **map = malloc(sizeof(int *) * map_size.y);

    for (int i = 0; getline(&line, &size, file) != -1; i++) {
        map[i] = malloc(sizeof(int) * map_size.x);
        line = remove_bsn(line);
        for (int j = 0; line[j] != '\0'; j++)
            map[i][j] = line[j] - '0';
    }
    free(line);
    fclose(file);
    return map;
}

int **make_map(game_t *game)
{
    game->map_size = map_size("map", game->map_size);
    if (game->map_size.x == 0 || game->map_size.y == 0)
        return NULL;
    return init_map_array("map", game->map_size);
}
