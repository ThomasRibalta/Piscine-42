/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:06:02 by thoribal          #+#    #+#             */
/*   Updated: 2023/09/14 14:06:05 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + ft_strlen(++str));
}

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	base_len = ft_strlen(base);
	if (base_len > 1)
	{
		while (i < base_len)
		{
			while (j < base_len)
			{
				if ((i != j && base[i] == base[j])
					|| base[i] == '-' || base[i] == '+'
					|| ft_is_space(base[i]))
					return (0);
				j++;
			}
			j = 0;
			i++;
		}
		return (1);
	}
	return (0);
}

int	is_char_in_base(char *base, char c, long int *value, int base_len)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*value += i;
			*value *= base_len;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	long int	r;
	int			minus_count;
	int			base_len;

	i = -1;
	r = 0;
	base_len = ft_strlen(base);
	minus_count = 0;
	if (check_base(base))
	{
		while (ft_is_space(str[++i]) || str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				minus_count++;
			if ((str[i] == '-' || str[i] == '+') && ft_is_space(str[i + 1]))
				return (0);
		}
		while (is_char_in_base(base, str[i], &r, base_len))
			i++;
		r /= base_len;
		if (minus_count % 2 == 1)
			r *= -1;
	}
	return (r);
}
