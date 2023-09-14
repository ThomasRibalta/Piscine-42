/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:46:03 by thoribal          #+#    #+#             */
/*   Updated: 2023/09/11 09:27:48 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *chars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i != 0 && ((is_charset(str[i], chars) == 1
					&& is_charset(str[i - 1], chars) == 0)
				|| str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !(is_charset(str[i], charset)))
		i++;
	return (i);
}

char	*get_word(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (ft_strlen(str, charset) + 1));
	while (i < ft_strlen(str, charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && is_charset(*str, charset))
			str++;
		if (*str != '\0')
		{
			tab[i] = get_word(str, charset);
			i++;
		}
		while (*str != '\0' && !(is_charset(*str, charset)))
			str++;
	}
	tab[i] = 0;
	return (tab);
}
