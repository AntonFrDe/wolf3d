/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** my
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Audio.h>

#ifndef MY_H_
#define pi 3.14159265358979323846

#define RAY 200
    #define MY_H_
#include "struct.h"
void draw_floor_and_ceilling(sfRenderWindow *window);
sfRenderWindow *window_create(void);
circle_t create_circle(float radius, sfVector2f location, sfColor color);
int display_window(map_t map);
square_t create_square(sfVector2f size, sfVector2f location,
    sfColor fill_color, float outline_thickness);
void display_square(square_t **squares, sfRenderWindow *window, int len);
square_t **init_squares(map_t map);
int is_loc_in_map(sfVector2f loc, map_t map);
line_t create_line(sfVector2f point1, sfVector2f point2, sfColor color);
sfVector2f angle_coor(sfVector2f point_coor, float angle, float len_circle);
line_t init_ray(int angle);
float ray_display(map_t map, sfVector2f center, float angle);
player_t *create_player(sfVector2f loc, int nb_ray);
a3d_t *init_3d(sfVector2f loc, int nb_lines, int lenght, int height);
void display_3d(map_t map, player_t *player, sfRenderWindow *window,
    a3d_t *a3d);
void print_2fv(sfVector2f vec);
void print_2iv(sfVector2i vec);
float float_modulo(float nb, float op);
void draw_line(sfRenderWindow *window, sfVector2f point2, sfVector2f point1,
    sfColor color);
sfVertexArray *create_quad(sfVector2f *point, sfColor color);
map_t init_map(char *name);
int display_menu(void);
void display_settings(sfMusic *music, int *volume);

#endif /* !MY_H_ */
