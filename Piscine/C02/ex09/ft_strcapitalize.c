/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:24:13 by ecorona-          #+#    #+#             */
/*   Updated: 2023/08/28 14:27:19 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;

	i = 1;
	while (str[i] != '\0')
	{
		c = str[i - 1];
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		if (!(is_lower(c) || is_upper(c) || is_digit(c)))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 'a' + 'A';
	return (str);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[] = "salut, comMent tu vas ? 42MOTS QuArante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(str));
}
*/
