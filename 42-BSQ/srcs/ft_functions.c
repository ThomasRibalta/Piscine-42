/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:32:02 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 22:41:13 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ftlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ftlen(src) * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	nb;

	sign = 1;
	nb = 0;
	i = 0;
	if (*str == '\0')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		str++;
	}
	return (nb * sign);
}
