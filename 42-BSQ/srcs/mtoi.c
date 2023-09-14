/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:50:25 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 22:44:13 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/map_structures.h"
#include "../includes/mtoi.h"
#include <stdio.h>

int	**mtoi(t_map map, int maxRow, int maxCol)
{
	int	row;
	int	col;
	int	**imap;

	row = 0;
	col = 0;
	imap = malloc(sizeof(int *) * maxRow + 1);
	while (row <= maxRow)
	{
		imap[row] = malloc(sizeof(int) * maxCol + 1);
		while (col < maxCol)
		{
			if (map.map_chars.empty == map.content[row + 1][col + 1])
			{
				imap[row][col] = 1;
			}
			else
			{
				imap[row][col] = 0;
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (imap);
}
