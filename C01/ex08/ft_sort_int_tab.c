/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:51:53 by thoribal          #+#    #+#             */
/*   Updated: 2023/09/14 11:00:19 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	c;
	int	storage;

	i = 0;
	while (i <= size)
	{
		c = i;
		while (c < size)
		{
			if (tab[c] < tab[i])
			{
				storage = tab[c];
				tab[c] = tab[i];
				tab[i] = storage;
			}
			c++;
		}
		i++;
	}
}
