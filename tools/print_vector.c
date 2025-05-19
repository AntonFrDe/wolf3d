/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-victor.delannoy
** File description:
** print_vector
*/

#include "../include/wolf.h"

void print_raycast(char *str, raycast_t ray)
{
    printf("------[%s]--------\n", str);
    printf("cam \t");
    print_2fv(ray.cam);
    printf("dir \t");
    print_2fv(ray.ray_dir);
    printf("delta \t");
    print_2fv(ray.delta_dist);
    printf("steps \t");
    print_2iv(ray.steps);
    printf("side \t");
    print_2fv(ray.side_dist);
    printf("-------------------\n");
}

void print_2iv(sfVector2i vec)
{
    printf("{%d, %d}\n", vec.x, vec.y);
}

void print_2fv(sfVector2f vec)
{
    printf("{%f, %f}\n", vec.x, vec.y);
}
