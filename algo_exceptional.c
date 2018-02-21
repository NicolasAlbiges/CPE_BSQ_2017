/*
** EPITECH PROJECT, 2017
** algo_exceptional.c
** File description:
** exceptional square of BSQ
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	one_line(info_t *info, char **map)
{
	int ct = 0;
	int ctb = 0;
	int b = 0;

	while (ctb != info->nb_cols) {
		if (map[ctb][ct] == '.' && b == 0) {
			map[ctb][ct] = 'x';
				b ++;
		}
		if (ct == info->nb_rows) {
			ctb ++;
			ct = 0;
		}
		ct ++;
	}
	return (0);
}
