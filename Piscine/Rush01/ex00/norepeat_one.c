/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norepeat_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:21:07 by ecorona-          #+#    #+#             */
/*   Updated: 2023/09/03 21:23:59 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

void	remove_number(int row, int col);

extern int	g_array[SIZE][SIZE][SIZE];

void	norepeat_one(void)
{
	int	count;
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			count = 0;
			k = 0;
			while (k < SIZE)
			{
				if (g_array[i][j][k] == 1)
					count++;
				k++;
			}
			if (count == 1)
				remove_number(i, j);
			j++;
		}
		i++;
	}
}
