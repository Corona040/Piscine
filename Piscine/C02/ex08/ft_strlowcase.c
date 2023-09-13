/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:53:17 by ecorona-          #+#    #+#             */
/*   Updated: 2023/08/28 10:57:27 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
			*(str + i) = *(str + i) - 'A' + 'a';
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "Eduardo Corona";

	printf("%s\n", ft_strlowcase(str));
}
*/
