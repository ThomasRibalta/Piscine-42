/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:30:58 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 14:58:22 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map_structures.h"

t_map_chars	check_card(t_map_chars card, char *str);
t_map		*get_maps(char **filenames, int fc);
void		map_error(void);
int			check_lines(t_map map);
int			is_map_error(t_map maps);
#endif
