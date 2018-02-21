/*
** EPITECH PROJECT, 2017
** bsq_main.c
** File description:
** the main of the func
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	fill_struct(char *buffer, info_t *info, int ct)
{
	int b = 0;
	int len = 0;

	info->nb_cols = 0;
	while (buffer[len] != '\n') {
		if (b == 0)
			info->nb_cols = info->nb_cols * 10 + (buffer[len] - 48);
		len ++;
		if (buffer[len] == '\n' && b == 0) {
			ct = len + 1;
			b ++;
			len ++;
		}
	}
	info->nb_rows = (len - ct + 1);
	info->lenght_tmp = 0;
	info->lenght = 0;
	return (ct);
}

char	**fill_string(int fd, char *buffer, info_t *info, long long int size)
{
	char **temp_map;
	int end_file = 0;
	int ct = 0;

	while ((end_file = read(fd, buffer, size)) > 0)
		buffer[size] = '\0';
	ct = fill_struct(buffer, info, ct);
	temp_map = mem_alloc_2d_arrai(buffer, info, ct);
	return (temp_map);
}

char	**storage_file(char **av, info_t *info)
{
	char *buffer;
	int fd = open(av[1], O_RDONLY);
	char **map;
	struct stat buf;

	if (stat(av[1], &buf) == -1)
		exit(84);
	if ((buffer = malloc(sizeof(char) * (buf.st_size + 1))) == NULL)
		exit(84);
	if (fd >= 0)
		map = fill_string(fd, buffer, info, buf.st_size);
	return (map);
}

int	main(int ac, char **av)
{
	(void)ac;
	char **map;
	info_t *info = malloc(sizeof(info_t));

	if (ac != 2)
		return (84);
	map = storage_file(av, info);
	if (info->nb_rows == 1 ||  info->nb_cols == 1) {
		one_line(info, map);
		disp_map(map , info->nb_cols, info);
		return (0);
	}
	execptional_square(map, info);
	info->lenght = info->lenght + 1;
	map = change_map(map , info);
	disp_map(map , info->nb_cols, info);
}
