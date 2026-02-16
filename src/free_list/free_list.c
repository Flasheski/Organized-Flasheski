/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** free_list
*/

#include "shell.h"
#include "my.h"

void free_list(infos_t *free_buffer)
{
    infos_t *list;

    while (free_buffer != NULL) {
        list = free_buffer;
        free_buffer = free_buffer->next;
        free(list->type);
        free(list->name);
        free(list);
    }
}
