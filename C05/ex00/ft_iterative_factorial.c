/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:58:15 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/30 11:20:05 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	total;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	total = nb;
	nb--;
	while (nb != 0)
	{
		total *= nb;
		nb--;
	}
	return (total);
}
