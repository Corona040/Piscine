/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:24:16 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 19:13:59 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (*(src + i) != '0')
		i++;
	dup = malloc(i * sizeof(char));
	if (dup == 0)
		return (0);
	i = 0;
	while (*(src + i) != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	char *dup;
	char *ft_dup;

	if (ac == 2)
	{
		dup = strdup(av[1]);
		ft_dup = ft_strdup(av[1]);
		printf("strdup: %s\nft_strdup: %s\n", dup, ft_dup);
	}
}
*/
