/*
** EPITECH PROJECT, 2025
** include
** File description:
** my_str_to_warr_custom
*/

#include "../include/wolf.h"

static int is_delimit(char a, char *del)
{
    for (int i = 0; del[i] != '\0'; i++)
        if (a == del[i])
            return 1;
    return 0;
}

static int nb_word(char *delimit, char *str)
{
    int nb_wrd = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (!is_delimit(str[i], delimit) && (str[i + 1] == '\0' ||
        is_delimit(str[i + 1], delimit)))
            nb_wrd++;
    return nb_wrd + 1;
}

static char *make_word(int i1, int i, char *word, char *str)
{
    int curr = 0;

    word = malloc(sizeof(char) * (i - i1 + 2));
    for (; i1 != i + 1; i1++) {
        word[curr] = str[i1];
        curr++;
    }
    word[curr] = '\0';
    return word;
}

static int is_start(char *str, char *delimit, int i)
{
    if (i == 0 && is_delimit(str[i], delimit) == 0)
        return 1;
    if (i == 0)
        return 0;
    if (is_delimit(str[i], delimit) == 0 &&
            is_delimit(str[i - 1], delimit) == 1)
        return 1;
    return 0;
}

char **my_str_to_word_array(char *str, char *delimit)
{
    int current_word = 0;
    int i1 = 0;
    char **array;

    if (!str || str[0] == '\0' || str == NULL || strlen(str) == 0)
        return NULL;
    array = malloc(sizeof(char *) * nb_word(delimit, str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_start(str, delimit, i))
            i1 = i;
        if (is_delimit(str[i], delimit) == 0 && (str[i + 1] == '\0' ||
            is_delimit(str[i + 1], delimit) == 1)) {
            array[current_word] = make_word(i1, i, array[current_word], str);
            current_word++;
        }
    }
    array[current_word] = NULL;
    return array;
}
