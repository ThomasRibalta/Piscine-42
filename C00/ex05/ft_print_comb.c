/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:44:54 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/23 13:02:11 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char a, char b, char c)
{
	if (a != b && b != c && a != c)
	{
		if (a == '7' && b == '8' && c == '9')
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, &c, 1);
		}
		else
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, &c, 1);
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a;
		b++;
		while (b <= '8')
		{
			c = b;
			c++;
			while (c <= '9')
			{
				ft_print(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
