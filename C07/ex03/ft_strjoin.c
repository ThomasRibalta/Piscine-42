/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:09:56 by thoribal          #+#    #+#             */
/*   Updated: 2023/09/05 13:59:19 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_fulllen(int n, char **str, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i != n)
	{
		len += ft_strlen(str[i]);
		if (i != n - 1)
			len += ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*text;
	int		len;
	int		i;

	i = 0;
	if (size == 0)
		return (malloc(sizeof(char)));
	len = ft_fulllen(size, strs, sep);
	text = malloc(len * sizeof(int));
	if (!text)
		return (NULL);
	while (i != size)
	{
		text = ft_strcat(text, strs[i]);
		if (i != size - 1)
			text = ft_strcat(text, sep);
		i++;
	}
	return (text);
}
