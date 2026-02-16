/*
** EPITECH PROJECT, 2025
** G-CPE-110-LIL-1-1-organized-9
** File description:
** bubble_sort
*/

#include "shell.h"
#include "my.h"

int put_crit_neg(int result, crit_t *crit)
{
    if (crit->rev)
        result = -result;
    return result;
}

int check_values(infos_t *a, infos_t *b)
{
    if (a == NULL && b == NULL)
        return 0;
    if (a == NULL)
        return -1;
    if (b == NULL)
        return 1;
    return 99;
}

int compare_by_str_types(infos_t *a, infos_t *b, crit_t *crit)
{
    if (my_strcmp(crit->str, "TYPE") == 0)
        return my_strcmp(a->type, b->type);
    if (my_strcmp(crit->str, "NAME") == 0)
        return my_strcmp(a->name, b->name);
    return 0;
}

int compare_by_str(infos_t *a, infos_t *b, crit_t *crit)
{
    int result = 0;
    int check_res = check_values(a, b);

    if (check_res != 99)
        return check_res;
    if (!crit || !crit->str)
        return 0;
    switch (crit->str[0]) {
        case 'T':
        case 'N':
            result = compare_by_str_types(a, b, crit);
            break;
        case 'I':
            if (my_strcmp(crit->str, "ID") == 0)
                result = a->id - b->id;
            break;
        default:
            return 0;
    }
    return put_crit_neg(result, crit);
}

int compare_elements(infos_t *a, infos_t *b, crit_t *crit, int nb_crit)
{
    int result = 0;

    for (int i = 0; i < nb_crit && result == 0; i++)
        result = compare_by_str(a, b, &crit[i]);
    return result;
}
