/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:05:17 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 16:18:34 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/map_structures.h"
#include "../includes/ft_functions.h"
#include <stdio.h>

void	close_maps(t_map *maps)
{
	int	i;

	i = 0;
	while (maps[i].fd != -2)
	{
		close(maps[i].fd);
		i++;
	}
}

void	update(t_map *map, int *i, int *j, char **content)
{
	(*j)++;
	content[*j] = malloc(BUFFER_SIZE * sizeof(char));
	map->x = *i - 1;
	*i = 0;
}

void	set_map_content(int fd, t_map *map)
{
	char	*buffer;
	int		i;
	int		j;
	int		buf;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	map->content = malloc(BUFFER_SIZE * sizeof(char *));
	i = 0;
	j = 0;
	map->content[j] = malloc(BUFFER_SIZE * sizeof(char));
	buf = read(fd, buffer, 1);
	while (buf > 0)
	{
		if (buffer[0] == '\n')
		{
			update(map, &i, &j, map->content);
		}
		map->content[j][i++] = buffer[0];
		buf = read(fd, buffer, 1);
	}
	map->y = j - 1;
	free(buffer);
}
