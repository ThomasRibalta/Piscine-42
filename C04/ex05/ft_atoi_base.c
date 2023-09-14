/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:47:11 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/30 08:52:27 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_erreur(char	*c)
{
	char	*c2;
	int		i;
	int		j;

	i = 0;
	c2 = c;
	while (c[i] != '\0')
	{
		j = i + 1;
		while (c2[j] != '\0')
		{
			if (c2[j] == c[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_power(char *base, char *str)
{
	int	c;
	int	pow;

	pow = ft_strlen(base);
	c = ft_strlen(str) - 1;
	while (c > 1)
	{
		pow = pow * ft_strlen(base);
		c--;
	}
	if (c == 0)
		pow = 1;
	return (pow);
}

int	to_decimal(char *str, char *base)
{
	int	i;
	int	sum;

	sum = 0;
	while (*str != '\0')
	{
		i = 0;
		while (base[i] != '\0')
		{
			if (base[i] == *str)
			{
				if (base[i] >= '0' && base[i] <= '9')
					sum += (*str - '0') * ft_power(base, str);
				else
					sum += i * ft_power(base, str);
				break ;
			}
			i++;
		}
		str++;
	}
	return (sum);
}

int	ft_atoi_base(char *str, char *base)
{
	int	count;
	int	total;

	count = 0;
	if (ft_erreur(base) == 1)
		return (0);
	while (*str == ' ' || (*str >= 0 && *str <= 31))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count++;
		str++;
	}
	if (*str < 31 || *str == ' ')
		return (0);
	total = to_decimal(str, base);
	if (count % 2 != 0)
		return (-total);
	return (total);
}
