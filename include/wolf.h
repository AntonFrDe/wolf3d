/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** wolf
*/



#ifndef WOLF_H_
    #define WOLF_H_
    #include "struct.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "overlay.h"
    #include "SFML/Graphics.h"
    #include "SFML/System.h"
    #include "SFML/Window.h"
    #define TILE_SIZE 15
    #define MAX_FPS_SIZE 64
    #define MINIMAP_SCALE 0.2f
    #define AIR 0
    #define DOOR 2
int main(void);
player_t init_player(void);
game_t *init_game(void);
int **make_map(game_t *game);
void display_game(game_t *game);
void cast_ray(game_t *game);
raycast_t calc_dda(game_t *game, raycast_t raycast);
void draw_ray(game_t *game, raycast_t raycast, int i);
char *remove_bsn(char *str);
void event_handling(game_t *game);
void print_2fv(sfVector2f vec);
void print_2iv(sfVector2i vec);
void print_raycast(char *str, raycast_t ray);
void draw_minimap(game_t *game);
switch_window_state_t display_menu(game_t *game);
switch_window_state_t display_settings(app_context_t *ctx, game_t *game);
void resize_background(menu_t *menu);
sfText *create_menu_text(sfFont *menu_text_font, const char *str,
    sfVector2f pos);
switch_window_state_t handle_mouse_events(app_context_t *ctx,
    text_elemets_t *texts, input_context_t *input, menu_t *menu);
void resize_settings_background(menu_t *menu);
void destroy_texts(text_elemets_t *texts);
app_t init_app(void);
switch_window_state_t play_game(game_t *game);
void display_hud(game_t *game);
context_t init_overlay(game_t *game);
void draw_txtr(game_t *game, raycast_t raycast, int i);
game_txtr_t init_game_texture(game_t *game);
void handle_events(game_t *game);
void floor_cast(game_t *game);
switch_window_state_t display_menu_in_game(app_context_t *ctx, game_t *game);
int key_evt(sfEvent event, sfKeyCode key, int pressed);
void draw_text_at(game_t *game, const char *str, sfVector2f position);
game_t *load_file(char *filename, game_t *game);
switch_window_state_t display_loadpage(game_t *game);
void save_file(char *filename, game_t *game);
char *my_superstrcat(int nb_elem, ...);

#endif /* !WOLF_H_ */
