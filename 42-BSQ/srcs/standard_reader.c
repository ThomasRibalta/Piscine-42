/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:35:28 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 21:15:44 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/standard_reader.h"
#include "../includes/ft_functions.h"
#include "../includes/map_structures.h"
#include "../includes/utils.h"
#include "unistd.h"
#include <stdlib.h>
#include <stdio.h>

t_map_chars	get_map_chars(char *buffer)
{
	t_map_chars	chars;
	int			len;

	len = ftlen(buffer) - 1;
	chars.empty = buffer[len - 3];
	chars.obstacle = buffer[len - 2];
	chars.full = buffer[len - 1];
	return (chars);
}

t_map	read_standard(void)
{
	t_map	map;
	int		y;
	int		my;
	int		x;
	char	*buffer;

	y = 0;
	buffer = malloc(sizeof(char) * 100000);
	read(0, buffer, 1000000);
	my = ft_atoi(buffer);
	map.map_chars = get_map_chars(buffer);
	map.content = malloc(sizeof(char *) * 100000);
	map.content[0] = malloc(sizeof(char) * 10000);
	map.content[0] = ft_strdup(buffer);
	map.content[ftlen(map.content[0])] = '\0';
	while (y < my)
	{
		x = 0;
		read(0, buffer, 100000);
		map.content[y + 1] = malloc(sizeof(char) * 100000);
		while (buffer[x] != 10)
		{
			map.content[y + 1][x] = buffer[x];
			x++;
		}
		map.content[y + 1][x] = '\n';
		y++;
	}
	map.x = x - 1;
	map.y = my - 1;
	map.fd = 0;
	free(buffer);
	return (map);
}
