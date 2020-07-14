/*
** EPITECH PROJECT, 2020
** lem_in
** File description:
** read and stuck the file in a buffer
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"

char **split_this(char *file, int lines)
{
    char **split = malloc(sizeof(char *) * (lines + 1));

    for (int i = 0; i != lines; i++)
        split[i] = malloc(sizeof(char) * (my_strlen(file) + 1));
    for (int i = 0, j = 0, z = 0; file[i] != '\0'; i++, z++) {
        if (file[i] == '\n') {
            split[j][z] = '\0';
            j++;
            z = 0;
            if (j == lines)
                break;
        }
        split[j][z] = file[i];
    }
    split[lines] = NULL;
    return (split);
}

static char **clean_buff(char **buff, int lines)
{
    char **str = malloc(sizeof(char *) * (lines + 1));
    int j = 0;

    for (int i = 0; i != lines; i++)
        str[i] = malloc(sizeof(char) * (my_strlen(buff[i]) + 1));
    for (int i = 0; i != lines; i++) {
        for (int k = 0; buff[i][j]; j++, k++) {
            if (buff[i][k] == '\n')
                k++;
            str[i][j] = buff[i][k];
        }
        str[i][j] = '\0';
        j = 0;
    }
    str[lines] = NULL;
    return (str);
}

char **read_file(values_t *v)
{
    long unsigned size = 10;
    char *buff = malloc(sizeof(char) * size);
    char *file;
    char **split;
    int i = 0;

    for (; getline(&buff, &size, stdin) != -1; i++) {
        if (i == 0) {
            file = malloc(sizeof(char) * (my_strlen(buff) + 1));
            for (int j = 0; j != my_strlen(buff); j++)
                file[j] = buff[j];
            continue;
        }
        file = my_strcat(file, buff);
    }
    if (i == 0)
        return (NULL);
    v->lines = i;
    split = split_this(file, i);
    split = clean_buff(split, i);
    free(buff);
    free(file);
    return (split);
}
