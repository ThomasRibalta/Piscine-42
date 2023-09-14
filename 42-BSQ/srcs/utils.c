/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:43:58 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 20:52:24 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_structures.h"
#include "../includes/ft_functions.h"
#include "../includes/files.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	map_error(void)
{
	ft_putstr("map_error\n");
}

t_map	*get_maps(char **filenames, int fc)
{
	t_map	*maps;
	t_map	map;
	int		i;

	i = 1;
	maps = malloc(sizeof(t_map) * (fc + 1));
	if (!maps)
	{
		map_error();
		exit(2);
	}
	while (i < fc)
	{
		map.fd = open(filenames[i], O_RDONLY);
		set_map_content(map.fd, &map);
		maps[i - 1] = map;
		i++;
	}
	maps[i - 1].fd = -2;
	return (maps);
}

int	is_map_error(t_map maps)
{
	int	j;

	j = 2;
	if (maps.fd == -1 || maps.fd == -2)
		return (1);
	while (maps.content[j])
	{
		if (ftlen(maps.content[1]) == ftlen(maps.content[j - 1]))
			j++;
		else
			return (1);
	}
	j = 2;
	return (0);
}

t_map_chars	check_card(t_map_chars	card, char *str)
{
	int	len;
	
	len = ftlen(str) - 3;
	if (str[len] == str[len + 1] || str[len] == str[len + 2]
		|| str[len + 1] == str[len + 2])
	{
		card.empty = 0;
		return (card);
	}
	card.empty = str[len];
	card.obstacle = str[len + 1];
	card.full = str[len + 2];
	return (card);
}

int	check_lines(t_map map)
{
	int	i;
	int	o;

	i = 1;
	o = 1;
	while (map.content[i])
	{
		if (!(map.content[i][o] == map.map_chars.empty
			|| map.content[i][o] == map.map_chars.obstacle
				|| map.content[i][o] == '\n'
				|| map.content[i][o] == '\0'))
		{
			return (1);
		}
		if (map.content[i][o] == '\0')
		{
			i++;
			o = -1;
		}
		o++;
	}
	if (i - 2 != map.y)
		return (1);
	return (0);}
