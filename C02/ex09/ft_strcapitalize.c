/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 08:10:25 by thoribal          #+#    #+#             */
/*   Updated: 2023/08/28 08:45:47 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	caps;

	ft_strlowcase(str);
	i = 0;
	caps = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			caps = 0;
		if (caps == 1 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
			caps = 0;
		}
		if (!(str[i] >= 'a' && str[i] <= 'z') 
			&& !(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= '0' && str[i] <= '9'))
			caps = 1;
		i++;
	}
	return (str);
}
