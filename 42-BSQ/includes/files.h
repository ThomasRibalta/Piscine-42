/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:30:29 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 11:18:55 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_structures.h"

void	close_maps(t_map *maps);

void	set_map_content(int fd, t_map *map);

void	update(t_map *map, int *i, int *j, char **content);
