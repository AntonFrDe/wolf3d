/*
** EPITECH PROJECT, 2025
** bootstrap_wolf3D
** File description:
** wolf
*/

#ifndef WOLF_H_
    #define WOLF_H_
    #define TILE_SIZE 64
    #define MAP_WIDTH 10
    #define MAP_HEIGHT 8

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>


typedef struct {
    float x;
    float y;
    float angle;
} Player;

extern int map[MAP_HEIGHT][MAP_WIDTH];

#endif /* !WOLF_H_ */
