/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:17:46 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 16:23:09 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (*(str + i) != '\0')
	{
		j = 0;
		while (*(to_find + j) == *(str + i + j))
		{
			if (*(to_find + j + 1) == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[] = "abcdefg";
	char to_find[] = "";
	printf("strstr:    %s\n", strstr(str, to_find));
	printf("ft_strstr: %s\n", ft_strstr(str, to_find));
}
*/
