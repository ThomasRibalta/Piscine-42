/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:39:14 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 09:37:52 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_STRUCTURES_H
# define MAP_STRUCTURES_H
# define BUFFER_SIZE 100000000

typedef struct s_map_chars
{
	char	empty;
	char	obstacle;
	char	full;
}	t_map_chars;

typedef struct s_map
{
	t_map_chars	map_chars;
	char		**content;
	int			fd;
	int			x;
	int			y;
	int			**imap;
}	t_map;

typedef struct s_rect
{
	int	map_fd;
	int	x;
	int	y;
	int	size;
}	t_rect;

typedef struct s_biggest
{
	int	row;
	int	col;
	int	value;
}	t_biggest;

#endif
