/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** add_node
*/

#include "my.h"
#include "shell.h"

int get_next_id(infos_t *head)
{
    int max_id = -1;

    if (head == NULL)
        return 0;
    while (head != NULL) {
        if (head->id > max_id)
            max_id = head->id;
        head = head->next;
    }
    max_id++;
    return max_id;
}

int check_name(char *type)
{
    if (!type)
        return 84;
    if (my_strcmp(type, "WIRE") == 0 ||
        my_strcmp(type, "ACTUATOR") == 0 ||
        my_strcmp(type, "DEVICE") == 0 ||
        my_strcmp(type, "SENSOR") == 0 ||
        my_strcmp(type, "PROCESSOR") == 0)
        return 0;
    return 84;
}

int check_list_in_add(infos_t *new_elms, char **args)
{
    if (new_elms == NULL)
        return 84;
    if (check_name(new_elms->type) == 84)
        return 84;
    if (args == NULL)
        return 84;
    return 0;
}

int add(void *data, char **args)
{
    infos_t **all_elms = (infos_t **)data;
    infos_t *new_elms = NULL;
    int id = 0;

    if (!all_elms || !args || !args[0])
        return 84;
    id = get_next_id(*all_elms);
    for (int i = 0; args[i] != NULL; i += 2) {
        if (args[i + 1] == NULL)
            return 84;
        new_elms = create_node(id, args[i], args[i + 1]);
        if (check_list_in_add(new_elms, args) == 84)
            return 84;
        new_elms->next = *all_elms;
        *all_elms = new_elms;
        print_add(new_elms);
        id++;
    }
    return 0;
}
