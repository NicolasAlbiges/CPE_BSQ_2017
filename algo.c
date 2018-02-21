/*
** EPITECH PROJECT, 2017
** algo.c
** File description:
** algorithme of the BSQ
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	line(char **map, int ct, int ctb, info_t *info)
{
	int temp = ct - 1;

	while (temp > (info->temp_x - 1)) {
		if (map[ctb][temp] == 'o') {
			return (1);
		}
		temp --;
	}
	temp = ctb - 1;
	while (temp > (info->temp_y - 1)) {
		if (map[temp][ct] == 'o')
			return (1);
		temp --;
	}
	return (0);
}

int     check_square(char **map, info_t *info, int ct, int len)
{
	if (line(map, ct, len, info) == 1) {
		return (1);
	} else
		info->lenght_tmp ++;
	return (0);
}

int	reset_square(char **map, info_t *info, int ct, int len)
{
	if (map[len][ct] != 'o' && map[len][ct] != '\n' && map[len][ct] != '\0') {
		if (check_square(map, info, ct, len) == 1)
			ct = info->nb_rows;
	}
	else
		ct = info->nb_rows;
	ct ++;
	return (ct);
}

int	find_bigest_square(char **map, info_t *info, int ct, int len)
{
	info->temp_x = ct;
	info->temp_y = len;
	ct = ct + 1;
	len = len + 1;
	while (ct < info->nb_rows && len < info->nb_cols) {
		ct = reset_square(map, info, ct, len);
		len ++;
	}
	if (info->lenght < info->lenght_tmp) {
		info->lenght = info->lenght_tmp;
		info->lenght_tmp = 0;
		info->pos_x = info->temp_x;
		info->pos_y = info->temp_y;
	}
	info->lenght_tmp = 0;
	return (0);
}

int	execptional_square(char **map, info_t *info)
{
	int ct = 0;
	int len = 0;

		while (len != info->nb_cols) {
		if (map[len][ct] != 'o' && map[len][ct] != '\n')
			find_bigest_square(map, info, ct, len);
		if (ct == info->nb_rows) {
			len ++;
			ct = 0;
		}
		ct ++;
	}
	return (0);
}
