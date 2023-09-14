/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:13:24 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/30 10:45:53 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tonum(char *str, int count)
{
	int	total;
	int	mult;

	mult = 1;
	total = 0;
	str--;
	while (*str >= '0' && *str <= '9')
	{
		total += (*str - '0') * mult;
		mult = mult * 10;
		str--;
	}
	if (count % 2 != 0)
		return (-total);
	return (total);
}

int	ft_atoi(char *str)
{
	int	count;

	count = 0;
	if (*str == '\0')
		return (0);
	while (*str == ' ' || (*str >= 0 && *str <= 31))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count++;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		str++;
	}
	return (ft_tonum(str, count));
}
