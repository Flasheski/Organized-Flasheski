/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** display_node
*/

#include "my.h"
#include "shell.h"

int disp(void *data, char **args)
{
    infos_t *all_elms = *(infos_t **)data;

    if (args[0] != NULL)
        return 84;
    while (all_elms != NULL) {
        print_display(all_elms->type, all_elms->id, all_elms->name);
        all_elms = all_elms->next;
    }
    return 0;
}
