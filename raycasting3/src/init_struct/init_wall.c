/*
** EPITECH PROJECT, 2025
** raycasting3
** File description:
** init_wall
*/

#include "../../include/wolf.h"

sfTexture **init_wall(sfTexture **wall)
{
    wall = malloc(sizeof(sfTexture *) * 8);
    wall[0] = sfTexture_createFromFile("Assets/pics/wood.png", NULL);
    wall[1] = sfTexture_createFromFile("Assets/pics/mossy.png", NULL);
    wall[2] = sfTexture_createFromFile("Assets/pics/bluestone.png", NULL);
    wall[3] = sfTexture_createFromFile("Assets/pics/colorstone.png", NULL);
    wall[4] = sfTexture_createFromFile("Assets/pics/eagle.png", NULL);
    wall[5] = sfTexture_createFromFile("Assets/pics/greenlight.png", NULL);
    wall[6] = sfTexture_createFromFile("Assets/pics/greystone.png", NULL);
    wall[7] = sfTexture_createFromFile("Assets/pics/redbrick.png", NULL);
    return wall;
}
