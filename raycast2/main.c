/*
** EPITECH PROJECT, 2025
** raycast2
** File description:
** main
*/

#include "wolf.h"
#include "struct.h"

static int display_hmsg(void)
{
    FILE *file = fopen("help_msg", "r");
    char *line = NULL;
    size_t size;

    if (file == NULL)
        return 84;
    while (getline(&line, &size, file) != -1)
        printf("%s", line);
    free(line);
    fclose(file);
    return 0;    
}

int main(int argc, char **argv)
{
    game_t *game;

    if (argc != 2)
        return 84;
    if (strcmp(argv[1], "-h") == 0)
        return display_hmsg();
    game = malloc(sizeof(game_t));
    if (init_struct(argv[1], game) == 84)
        return 84;
    return display_game(game);
}
