/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** functions_sort
*/

#include "shell.h"
#include "my.h"

void swap_array_elms(infos_t **array, int i, int j)
{
    infos_t *tmp = array[i];

    array[i] = array[j];
    array[j] = tmp;
}

int partition(infos_t **array, int min_low, int max_high,
    sort_params_t *params)
{
    infos_t *tmp = array[max_high];
    int i = min_low - 1;

    for (int j = min_low; j < max_high; j++) {
        if (compare_elements(array[j], tmp, params->crit,
                params->nb_crit) <= 0) {
            i++;
            swap_array_elms(array, i, j);
        }
    }
    swap_array_elms(array, i + 1, max_high);
    return i + 1;
}

void quick_sort(infos_t **array, int min_low, int max_high,
    sort_params_t *params)
{
    int idx;

    if (min_low < max_high) {
        idx = partition(array, min_low, max_high, params);
        quick_sort(array, min_low, idx - 1, params);
        quick_sort(array, idx + 1, max_high, params);
    }
}
