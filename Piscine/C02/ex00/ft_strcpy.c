/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:22:24 by ecorona-          #+#    #+#             */
/*   Updated: 2023/08/29 17:52:22 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (*(src + i) == '\0')
		*(dest + i) = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest1[] = "banana";
	char	dest2[] = "banana";
	char	src[] = "man";

	printf("strcpy: %s\n", strcpy(dest1, src));
	printf("ft_strcpy: %s\n", ft_strcpy(dest2, src));
}
*/
