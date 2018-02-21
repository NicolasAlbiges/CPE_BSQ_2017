/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** functions about the map
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	disp_map(char **map , int nb_cols, info_t *info)
{
	int ct = 0;

	while (ct != nb_cols) {
		write(1, map[ct], info->nb_rows);
		ct ++;
	}
	return (0);
}

char	**change_map(char **map , info_t *info)
{
	int ct = info->pos_x;
	int ctb = info->pos_y;

	if (info->lenght == 1)
		return (map);
	while (ctb != (info->lenght + info->pos_y)) {
		while (ct != (info->lenght + info->pos_x)) {
			map[ctb][ct] = 'x';
			ct ++;
		}
		ct = info->pos_x;
		ctb ++;
	}
	return (map);
}

char	**mem_alloc_2d_arrai(char *arr, info_t *info, int ctp)
{
	int ct = 0;
	int ctb = 0;
	char **array = malloc(sizeof(char*) * (info->nb_cols + 1));

	while (ct != info->nb_cols) {
		array[ct] = malloc(sizeof(char) * info->nb_rows + 1);
		while (ctb != info->nb_rows) {
			array[ct][ctb] = arr[ctp];
			ctb ++;
			ctp ++;
		}
		ctb = 0;
		array[ct][info->nb_rows] = '\0';
		ct ++;
	}
	array[info->nb_cols] = NULL;
	return (array);
}
