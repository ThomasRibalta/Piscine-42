/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:24:54 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 22:44:44 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/map_structures.h"
#include "../includes/ft_functions.h"
#include "../includes/mtoi.h"
#include "../includes/utils.h"
#include "../includes/bsq_solver.h"
#include <stdio.h>

int	check_errors(t_map map)
{
	if (is_map_error(map) || check_lines(map)
		|| map.map_chars.empty == 0)
	{
		return (1);
	}
	return (0);
}

void	cut(int **_mtoi, int j, t_map map, t_biggest biggest)
{
	int	i;

	i = 0;
	while (j < map.y)
	{
		while (i < map.x)
		{
			if (j + biggest.value - 1 >= biggest.row && j + biggest.value
				<= biggest.row + biggest.value && i + biggest.value - 1
				>= biggest.col && i + biggest.value <= biggest.col + biggest.value)
				ft_putchar(map.map_chars.full);
			else
			{
				if (_mtoi[j][i] == 0)
					ft_putchar(map.map_chars.obstacle);
				else if (_mtoi[j][i] > 0)
					ft_putchar(map.map_chars.empty);
			}
			i++;
		}
		ft_putchar('\n');
		i = 0;
		free(_mtoi[j]);
		j++;
	}
}

void	aff_result(int count, t_map *maps, int is_stdin)
{
	t_biggest	biggest;
	int			**_mtoi;
	int			j;
	t_map		map;

	j = 0;
	map = maps[count];
	if (!is_stdin)
		map.map_chars = check_card(map.map_chars, map.content[0]);
	_mtoi = mtoi(map, map.y + is_stdin, map.x + is_stdin);
	if (check_errors(map))
	{
		map_error();
		free(_mtoi);
		return ;
	}
	biggest = get_biggest(_mtoi, map.y + is_stdin, map.x + is_stdin);
	cut(_mtoi, j, map, biggest);
	free(_mtoi);
}
