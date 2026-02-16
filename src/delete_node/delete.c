/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** delete
*/

#include "shell.h"
#include "my.h"

void delete_node(infos_t **actual, infos_t **previous_one, infos_t **all_elms)
{
    infos_t *deleted = *actual;

    if (*previous_one == NULL)
        *all_elms = (*actual)->next;
    else
        (*previous_one)->next = (*actual)->next;
    print_delete_node(deleted->name, deleted->id, deleted->type);
    free_delete(deleted);
}

int del(void *data, char **args)
{
    int i = 0;
    int deleted_id;
    infos_t **all_elms = (infos_t **)data;
    infos_t *actual = NULL;
    infos_t *previous_one = NULL;

    if (all_elms == NULL || args == NULL || !args[0])
        return 84;
    for (; args[i] != NULL; i++) {
        deleted_id = my_getnbr(args[i]);
        previous_one = NULL;
        actual = *all_elms;
        for (; actual && actual->id != deleted_id; actual = actual->next)
            previous_one = actual;
        if (!actual)
            return 84;
        delete_node(&actual, &previous_one, all_elms);
    }
    return 0;
}
