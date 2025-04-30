/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** init_map
*/

#include "wolf.h"

static sfVertexArray *create_vertex_wall(game_t *game, int i, int j)
{
    sfVector2f *corners = malloc(sizeof(sfVector2f) * 4);
    
    corners[0] = (sfVector2f){.x = game->map.wall_size.x * j,
        .y  = game->map.wall_size.y * i};
    corners[1] = (sfVector2f){.x = game->map.wall_size.x * (j + 1),
        .y  = game->map.wall_size.y * i};
    corners[2] = (sfVector2f){.x = game->map.wall_size.x * (j + 1),
        .y  = game->map.wall_size.y * (i + 1)};
    corners[3] = (sfVector2f){.x = game->map.wall_size.x * j,
        .y  = game->map.wall_size.y * (i + 1)};
    return create_quad(corners, game->map.wall[i][j] == 1 ? sfWhite : sfBlack);
}

static int check_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] != '1' && line[i] != '0')
            return 84;
    return 0;
}

static int map_size(char *map_file, game_t *game)
{
    FILE *file = fopen(map_file, "r");
    char *line = NULL;
    size_t size;
    int i = 0;

    if (file == NULL)
        return 84;
    for (; getline(&line, &size, file) != -1; i++) {
        line = remove_bsn(line);
        if (check_line(line) == 84)
            return 84;
        if (i == 0)
            game->map.size.x = strlen(line);
        if (strlen(line) != game->map.size.x)
            return 84;
    }
    free(line);
    fclose(file);
    game->map.size.y = i;
    return 0;
}

static void init_map_array(game_t *game, char *map_file)
{
    FILE *file = fopen(map_file, "r");;
    char *line = NULL;
    size_t size;

    for (int i = 0; getline(&line, &size, file) != -1; i++) {
        game->map.wall[i] = malloc(sizeof(int) * game->map.size.x);
        game->map.vertex[i] = malloc(sizeof(sfVertexArray *) * game->map.size.x);
        for (int j = 0; line[j] != '\0'; j++) {
            game->map.wall[i][j] = line[j] == '1';
            game->map.vertex[i][j] = create_vertex_wall(game, i, j);
        }
    }
    free(line);
    fclose(file);
}

static game_t *init_map_ground(game_t *game)
{
    sfVector2f *corners = malloc(sizeof(sfVector2f) * 4);
    
    game->map.ground_color = (sfColor ){34, 67, 81, 255};
    corners[0] = (sfVector2f){.x = 0, .y  = HEIGHT / 2 - 75};
    corners[1] = (sfVector2f){.x = WIDTH, .y = HEIGHT / 2 - 75};
    corners[2] = (sfVector2f){.x = WIDTH, .y  = HEIGHT};
    corners[3] = (sfVector2f){.x = 0, .y  = HEIGHT};
    game->map.ground = create_quad(corners, game->map.ground_color);
    return game;
}

int init_map(char *map_file, game_t *game)
{
    if (map_size(map_file, game) == 84)
        return 84;
    game->map.wall = malloc(sizeof(int *) * game->map.size.y);
    game->map.vertex = malloc(sizeof(sfVertexArray **) * game->map.size.y);
    game->map.wall_size = (sfVector2f ){.x = WIDTH / (game->map.size.x * 5),
        .y = HEIGHT / (game->map.size.y * 3)};
    init_map_array(game, map_file);
    game = init_map_ground(game);
    return 0;
}