/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:24:54 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/28 08:26:00 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				l;

	l = ft_length(src);
	i = 0;
	if (size == 0)
		dest[i] = '\0';
	while (src[i] != '\0' && (size - 1) != 0)
	{
		if (size == i)
		{
			dest[i] = '\0';
			break ;
		}
		dest[i] = src[i];
		i++;
	}
	return (l);
}
