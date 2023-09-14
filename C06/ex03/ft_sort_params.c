/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:21:01 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/31 11:09:07 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c)
{
	write(1, c, 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] < s2[i] || s2[i] < s1[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

void	ft_swap(char **c1, char **c2)
{
	char	*temp;

	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

int	main(int argc, char **argv)
{
	int	i;
	int	c;

	i = 1;
	while (i < argc - 1)
	{
		c = 1;
		while (c < argc - 1)
		{
			if (ft_strcmp(argv[c], argv[c + 1]) > 0)
			{
				ft_swap(&argv[c], &argv[c + 1]);
			}
			c++;
		}
		i++;
	}
	i = 1;
	while (i != argc)
	{
		ft_putchar(argv[i]);
		i++;
	}
}


