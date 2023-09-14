/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solver.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:25:12 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 11:11:28 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_SOLVER_H
# define BSQ_SOLVER_H

# include "map_structures.h"

t_biggest	get_biggest(int **map, int maxRow, int maxCol);
int			ft_min(int a, int b, int c);
int			ft_max(int a, int b);
#endif
