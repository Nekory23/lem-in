/*
** EPITECH PROJECT, 2020
** lem-in
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"

static void free_buff(values_t *v)
{
    for (int i = 0; i != v->lines; i++)
        free(v->str[i]);
    for (int i = 0; v->ant->rooms[i] != NULL; i++)
        free(v->ant->rooms[i]);
    for (int i = 0; v->ant->tunnels[i] != NULL; i++)
        free(v->ant->tunnels[i]);
    free(v->ant->rooms);
    free(v->ant->start);
    free(v->ant->end);
    free(v->ant);
    free(v->str);
    free(v);
}

static int start (values_t *v)
{
    v->str = read_file(v);
    v->err_lines = SUCCESS;
    if (v->str == NULL)
        return (ERROR);
    del_com(v);
    my_putstr("#number_of_ants\n");
    if (first_display(v) == ERROR)
        return (ERROR);
//    free_buff(v);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    values_t *v = malloc(sizeof(values_t));

    if (v == NULL)
        return (ERROR);
    v->ant = malloc(sizeof(anthill_t));
    if (v->ant == NULL)
        return (ERROR);
    if (ac != 1 || av[0] == NULL)
        return (write_error(STR_ERROR_ARG));
    return (start(v));
}
