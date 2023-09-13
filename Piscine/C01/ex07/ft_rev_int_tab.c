/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:33:29 by ecorona-          #+#    #+#             */
/*   Updated: 2023/08/26 19:56:08 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		temp = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = temp;
		i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	array[5] = {1, 2, 3, 4, 5};
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("%i ", array[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_rev_int_tab(array, 5);
	while (i < 5)
	{
		printf("%i ", array[i]);
		i++;
	}
}
*/
