/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:26:03 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 20:34:20 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 4

extern int	g_array[SIZE][SIZE][SIZE];

int	power(int base, int power)
{
	int	i;
	int	result;

	i = power;
	result = 1;
	while (i > 0)
	{
		result *= base;
		i--;
	}
	return (result);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

int	square_min(int *square)
{
	int	nb;

	nb = 0;
	while (nb < SIZE)
	{
		if (square[nb] == 1)
			return (nb);
		nb++;
	}
	return (-1);
}

void	smaller(int *square_smaller, int *square_bigger)
{
	if (square_min(square_smaller) >= square_min(square_bigger))
	{
		square_bigger[square_min(square_bigger)] = 0;
	}
}

int	get_square_id(int row, int col)
{
	int	nb;
	int	id;

	id = 0;
	nb = 0;
	while (nb < SIZE)
	{
		id += g_array[row][col][nb] * power(2, nb);
		nb++;
	}
	return (id);
}
