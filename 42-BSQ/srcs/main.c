/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:58:36 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 18:26:27 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/files.h"
#include "../includes/ft_functions.h"
#include "../includes/map_structures.h"
#include <stdio.h>
#include "../includes/bsq_solver.h"
#include "../includes/result_printer.h"
#include <stdlib.h>
#include "../includes/standard_reader.h"

void	go_free(t_map *maps, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < count)
	{
		while(j < maps[i].y)
		{
			free(maps[i].content[j]);
			j++;
		}
		j = 0;
		free(maps[i].content);
		i++;
	}
	//free(maps[i].content[j]);
	//free(maps[i].content);
	free(maps);
}

int	main(int argc, char **argv)
{
	int	count;
	t_map	*maps;
	int	is_stdin;

	if (argc <= 1)
	{
		maps = malloc(sizeof(t_map) * 1);
		maps[0] = read_standard();
		argc++;
		is_stdin = 1;
	}
	else
	{
		maps = get_maps(argv, argc);
		close_maps(maps);
		is_stdin = 0;
	}
	count = 0;
	while (count != argc - 1)
	{
		aff_result(count, maps, is_stdin);
		count++;

	}
	go_free(maps, count);
	return (0);
}
