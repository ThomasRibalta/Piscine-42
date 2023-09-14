/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:53 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/31 08:53:59 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_erreur(char *c)
{
	char	*c2;
	int		i;
	int		j;

	i = 0;
	c2 = c;
	if (ft_size(c) < 2)
		return (1);
	while (c[i] != '\0')
	{
		j = i + 1;
		while (c2[j] != '\0')
		{
			if (c[i] == c2[j])
				return (1);
			j++;
		}
		if (c[i] <= 31 || c[i] == 45 || c[i] == 43)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_erreur(base) == 1)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / ft_size(base), base);
		write(1, base + (nbr % ft_size(base)), 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr < ft_size(base))
	{
		write(1, base + nbr, 1);
	}
	else
	{
		ft_putnbr_base(nbr / ft_size(base), base);
		ft_putnbr_base(nbr % ft_size(base), base);
	}
}
