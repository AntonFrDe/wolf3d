/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** init_map
*/

#include "include/my.h"
#include "include/struct.h"

static int get_len(char *name)
{
    int len = 0;
    char *line = NULL;
    size_t size = 0;
    FILE *file = fopen(name, "r");

    if (file == NULL)
        return 0;
    for (; getline(&line, &size, file) != -1; len++);
    free(line);
    fclose(file);
    return len;
}

static map_t make_map(char *name)
{
    map_t map;
    FILE *file;
    size_t size = 0;
    char *line = NULL;

    map.len = get_len(name);
    map.map = NULL;
    if (map.len < 1)
        return map;
    file = fopen(name, "r");
    map.map = malloc(sizeof(int *) * map.len);
    for (int i = 0; getline(&line, &size, file) != -1; i++) {
        map.map[i] = malloc(sizeof(int) * map.len);
        for (int j = 0; line[j] != '\n' && line[j] != '\0'; j++)
            map.map[i][j] = line[j] == '1';
    }
    free(line);
    fclose(file);
    return map;
}

map_t init_map(char *name)
{
    map_t map;

    map = make_map(name);
    if (map.map == NULL)
        return map;
    map.square_l = 1920 / (map.len * 3);
    map.square_w = 1080 / (map.len * 3);
    map.squares = init_squares(map);
    map.bool_map = 0;
    return map;
}
