/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:30:41 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 15:51:15 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq_solver.h"
#include "../includes/map_structures.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	return (c);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	check_new_max(int **map, int row, int col, t_biggest	*biggest)
{
	map[row][col] = ft_min(map[row - 1][col],
			map[row][col - 1], map[row - 1][col - 1]) + 1;
	if (ft_max(biggest->value, map[row][col]) > biggest->value)
	{
		biggest->row = row;
		biggest->col = col;
	}
	biggest->value = ft_max(biggest->value, map[row][col]);
}

t_biggest	get_biggest(int **map, int maxRow, int maxCol)
{
	int			row;
	int			col;
	t_biggest	biggest;

	row = 0;
	col = 0;
	biggest.value = 0;
	while (row < maxRow)
	{
		while (col < maxCol)
		{
			if (row == 0 || col == 0)
				biggest.value = ft_max(biggest.value, map[row][col]);
			else if (map[row][col] == 1)
			{
				check_new_max(map, row, col, &biggest);
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (biggest);
}
