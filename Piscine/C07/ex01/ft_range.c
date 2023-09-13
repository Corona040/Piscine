/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:38:09 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/06 19:14:02 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	if (min >= max)
		return (0);
	array = malloc((max - min) * (sizeof i));
	if (array == 0)
		return (0);
	i = min;
	while (i < max)
	{
		*(array + i - min) = i;
		i++;
	}
	return (array);
}

/*
#include <stdio.h>

int	main(int ac, char **av)
{
	int *array;
	int	i;

	if (ac == 3)
	{
		array = ft_range(atoi(av[1]), atoi(av[2]));
		i = atoi(av[1]);
		while (i < atoi(av[2]))
		{
			printf("%i; ", array[i - atoi(av[1])]);
			i++;
		}
	}
}
*/
