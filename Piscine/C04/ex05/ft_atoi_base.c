/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:25:17 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/08 11:28:27 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_pos(char *base, char d)
{
	int	i;

	i = 0;
	while (*(base + i) != '\0' && *(base + i) != d)
		i++;
	if (*(base + i) == '\0')
		return (-1);
	return (i);
}

int	ft_strlen(char *base, char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0' && find_pos(base, *(str + i)) >= 0)
		i++;
	return (i);
}

long int	power(int base, unsigned int power)
{
	unsigned int	i;
	long int		result;

	result = 1;
	i = 0;
	while (i < power)
	{
		result *= base;
		i++;
	}
	return (result);
}

int	check_args(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (*(base + i) != '\0')
	{
		j = 0;
		while (*(base + j) != '\0')
		{
			if (*(base + i) == *(base + j) && i != j)
				return (-1);
			j++;
		}
		if (*(base + i) == '+' || *(base + i) == '-')
			return (-1);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	long int	result;
	int			base_len;
	int			str_len;
	int			i;

	base_len = check_args(base);
	if (base_len > 1)
	{
		result = 0;
		sign = 1;
		while ((*str >= '\t' && *str <= '\r') || *str == ' ')
			str++;
		while (*str == '+' || *str == '-')
			if (*str++ == '-')
				sign *= -1;
		i = 0;
		str_len = ft_strlen(base, str);
		while ((find_pos(base, *str) >= 0) && (*str != '\0'))
			result += (find_pos(base, *str++)
					* power(base_len, str_len - 1 - i++));
		return (result * sign);
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_atoi_base("jose", "jose"));
	printf("%i\n", ft_atoi_base("-80000000", "0123456789abcdef"));
}
*/
