/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:09:14 by ecorona-          #+#    #+#             */
/*   Updated: 2023/08/31 16:50:31 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_lower(char c)
{
	return (c < 'a' || c > 'z');
}

int	not_upper(char c)
{
	return (c < 'A' || c > 'Z');
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((not_lower(*(str + i))) && (not_upper(*(str + i))))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_str_is_alpha("strING"));
}
*/
