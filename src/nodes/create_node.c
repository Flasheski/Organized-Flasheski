/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** create_node
*/

#include "shell.h"
#include "my.h"

infos_t *create_node(int id, char *type, char *name)
{
    infos_t *new_node = malloc(sizeof(infos_t));

    if (!new_node)
        return NULL;
    new_node->name = my_strdup(name);
    if (!new_node->name) {
        free(new_node);
        return NULL;
    }
    new_node->id = id;
    new_node->type = my_strdup(type);
    if (!new_node->type)
        return NULL;
    new_node->next = NULL;
    return new_node;
}
