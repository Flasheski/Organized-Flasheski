/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** free_delete
*/

#include "shell.h"
#include "my.h"

void free_delete(infos_t *deleted)
{
    free(deleted->name);
    free(deleted->type);
    free(deleted);
}
