/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:38:39 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/27 11:48:02 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	c;

	c = n;
	i = 0;
	while (src[i] != '\0')
	{
		if (i != c)
		{
			dest[i] = src[i];
		}
		else
		{
			break ;
		}
		i++;
	}
	while (i < c)
	{
		dest[i] = '\0';
		i ++;
	}
	return (dest);
}
