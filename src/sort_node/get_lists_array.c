/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** get_lists_array
*/

#include "shell.h"
#include "my.h"

int count_elms(infos_t *list)
{
    int count = 0;

    for (; list != NULL; list = list->next)
        count++;
    return count;
}

infos_t **list_to_array(infos_t *list, int len)
{
    infos_t **array = malloc(sizeof(infos_t *) * len);
    int i = 0;

    if (array == NULL)
        return NULL;
    while (list != NULL & i < len) {
        array[i] = list;
        list = list->next;
        i++;
    }
    if (i != len) {
        free(array);
        return NULL;
    }
    return array;
}

void array_to_list(infos_t **array, int len, infos_t **all_elms)
{
    if (len == 0 || array == NULL) {
        *all_elms = NULL;
        return;
    }
    *all_elms = array[0];
    for (int i = 0; i < len - 1; i++)
        array[i]->next = array[i + 1];
    array[len - 1]->next = NULL;
}
