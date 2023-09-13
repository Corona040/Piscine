/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:34:23 by ecorona-          #+#    #+#             */
/*   Updated: 2023/08/27 13:42:24 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	hold;
	int	i;

	i = 1;
	while (i < size)
	{
		if (*(tab + i) < *(tab + i - 1))
		{
			hold = *(tab + i);
			*(tab + i) = *(tab + i - 1);
			*(tab + i - 1) = hold;
			ft_sort_int_tab(tab, size);
		}
		i++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int array[] = {-44, 85, 30, 0, 40, -75, -95, 72, 43, -92, 0, 40, 0};
	ft_sort_int_tab(array, 13);
	for (int i = 0; i < 13; i++)
	{
		printf("%i, ", array[i]);
	}
}
*/
