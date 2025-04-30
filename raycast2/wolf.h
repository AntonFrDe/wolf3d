/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** wolf
*/

#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef WOLF_H_
    #define WIDTH 1920
    #define HEIGHT 1080
    #define FPS 32
    #define pi 3.14159265358979323846
    #define WOLF_H_
    #define RAY 1920
    #include "struct.h"
int main(int argc, char **argv);
int display_game(game_t *game);
sfVertexArray *create_quad(sfVector2f *point, sfColor color);
void render_display(game_t *game);
int init_struct(char *map_file, game_t *game);
char *remove_bsn(char *str);
void print_2iv(sfVector2i vec);
void print_2fv(sfVector2f vec);
void event_handling(game_t *game);
sfVector2f angle_coor(sfVector2f point_coor, float angle, float len_circle);
int is_loc_in_map(sfVector2f loc, const map_t map);
void draw_line(sfRenderWindow *window, sfVector2f point2,
    sfVector2f point1, sfColor color);
void set_ray(game_t *game);
void draw_ray(game_t *game);
void draw_3d(game_t *game);
void free_struct(game_t *game);
int init_map(char *map_file, game_t *game);


#endif /* !WOLF_H_ */
