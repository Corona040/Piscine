/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:48:08 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/07 19:42:21 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	*range = malloc((max - min) * (sizeof i));
	if (*range == 0)
		return (-1);
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = min;
	while (i < max)
	{
		*(*range + i - min) = i;
		i++;
	}
	return (i - min);
}

/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int res;
	int *array;
	int	i;

	if (ac == 3)
	{
		res = ft_ultimate_range(&array, atoi(av[1]), atoi(av[2]));
		i = atoi(av[1]);
		printf("array size: %i\nrange: ", res);
		while (i < atoi(av[2]))
		{
			printf("%i; ", array[i - atoi(av[1])]);
			i++;
		}
	}
}
*/
