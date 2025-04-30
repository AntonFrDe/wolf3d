/*
** EPITECH PROJECT, 2025
** B-PSU-200-TLS-2-1-minishell1-anton.franc-delbourg
** File description:
** remove_bsn
*/

#include "wolf.h"

char *remove_bsn(char *str)
{
    int i;

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++);
    str[i] = '\0';
    return str;
}
